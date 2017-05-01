{{define "odeFB"}}// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}{{$basicFB := $block.BasicFB}}{{$cvodeEnabled := .CvodeEnabled}}
// This file represents the implementation of the ODE / Hybrid Automata Function Block for {{$block.Name}}
#include "{{$block.Name}}.h"

{{template "_fbinit" .}}

int LREALEqual(LREAL a, LREAL b) {
	if(a > b) {
		return (a-b) < 1e-8;
	}
	return (b-a) < 1e-8;
}

{{if $basicFB.Algorithms}}//algorithms
{{range $algIndex, $alg := $basicFB.Algorithms}}
{{if algorithmNeedsCvode $alg}}
static int {{$block.Name}}_{{$alg.Name}}_ode_f(realtype t, N_Vector ode_solution, N_Vector ode_solution_dot, void *user_data) {
	//AUTOGENERATED CODE: this function represents the ODE in {{$block.Name}}'s {{$alg.Name}} algorithm
	//it is in a format that CVODE can process.
	{{$block.Name}}_t *me = ({{$block.Name}}_t*)user_data;
	{{$odeTick := parseOdeRunAlgo .Other.Text}}{{range $varIndex, $var := $odeTick.Vars}}
	NV_Ith_S(ode_solution_dot, {{$varIndex}}) = {{$func := getCECCTransitionCondition $block $var.VarValue}}{{fixOdeVarNameInF $func.IfCond $var.VarName $varIndex}};
	{{end}}
	return 0;
}

static int {{$block.Name}}_{{$alg.Name}}_ode_g(realtype t, N_Vector ode_solution, realtype *gout, void *user_data) {
	//AUTOGENERATED CODE: this function represents the roots of the ODE in {{$block.Name}}'s {{$alg.Name}} algorithm
	//it is in a format that CVODE can process.
	{{$odeTick := parseOdeRunAlgo .Other.Text}}{{range $varIndex, $var := $odeTick.Vars}}
	gout[{{$varIndex}}] = NV_Ith_S(ode_solution, {{$varIndex}}) - ({{$func := getCECCTransitionCondition $block $var.TriggerValue}}{{$minusVal := fixOdeVarNameInF $func.IfCond $var.VarName $varIndex}}{{if $minusVal}}{{$minusVal}}{{else}}0{{end}});
	{{end}}
	return 0;
}

//return 1 if we found a root
int {{$block.Name}}_{{$alg.Name}}({{$block.Name}}_t *me) {
	//AUTOGENERATED CODE: this function manages iterations of the ODE in {{$block.Name}}'s {{$alg.Name}} algorithm
	//It calls the CVODE solver and sets the outputs of the HA FB.
	if(me->solveInProgress == 0) {
		me->Tnext += me->DeltaTime;
		me->solveInProgress = 1; //solveInProgress is used to mark if we are currently solving
	}
	int flag = CVode(me->cvode_mem, me->Tnext, me->ode_solution, &me->Tcurr, CV_NORMAL);
	if (flag < 0) {
		fprintf(stderr, "Error in CVode: %d\n", flag);
		while(1);
	} 
	
	{{$odeTick := parseOdeRunAlgo .Other.Text}}{{range $varIndex, $var := $odeTick.Vars}}
	me->{{$var.VarName}} = NV_Ith_S(me->ode_solution, {{$varIndex}});
	{{end}}{{range $varIndex, $var := $odeTick.EmitVars}}
	me->{{$var.VarName}} = {{$trans := getCECCTransitionCondition $block $var.VarValue}}{{$trans.IfCond}};
	{{end}}

	if(flag == CV_ROOT_RETURN) {
		return 1;
	}

	me->solveInProgress = 0;
	return 0;
}

{{else if algorithmNeedsCvodeInit $alg}}
void {{$block.Name}}_{{$alg.Name}}({{$block.Name}}_t *me, CVRhsFn ode_f, CVRootFn ode_g) {
	//AUTOGENERATED CODE: this algorithm specifies the initialization of a CVODE SUNDIALS solver and was parsed from the algorithm's text field
	int flag;
	{{$odeInit := parseOdeInitAlgo .Other.Text}}
	//specify tolerances
	realtype reltol = 1e-6;
    realtype abstol = 1e-8;

	//free solver if it is initialized
	if(me->cvode_mem != NULL) {
		CVodeFree(&me->cvode_mem);
		N_VDestroy_Serial(me->ode_solution);  /* Free y vector */
	}

	//create solver
	me->ode_solution = N_VNew_Serial({{len $odeInit.GetInitialValues}}); //length of initial values
	me->cvode_mem = CVodeCreate(CV_ADAMS, CV_FUNCTIONAL);
	if (me->cvode_mem == 0) {
		fprintf(stderr, "Error in CVodeMalloc: could not allocate\n");
		while(1);
	}

	//specify initial values
	{{range $initVarIndex, $initVar := $odeInit.GetInitialValues}}
	NV_Ith_S(me->ode_solution, {{$initVarIndex}}) = {{$trans := getCECCTransitionCondition $block $initVar.VarValue}}{{$trans.IfCond}};
	{{end}}
		
	me->T0 = me->Tcurr; //set T0 to whatever real time we were counting from before
	
	if(me->solveInProgress == 0) { //only reset Tnext if we aren't currently solving (sometimes we might be taking a mid-tick transition)
		me->Tnext = me->Tcurr;
	}

	//initialize solver with pointer to values
	flag = CVodeInit(me->cvode_mem, ode_f, me->T0, me->ode_solution);
    if (flag < 0) {
		fprintf(stderr, "Error in CVodeMalloc: %d\n", flag);
		while(1);
    }

	flag = CVodeSetUserData(me->cvode_mem, me);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSetUserData: %d\n", flag);
		while(1);
    }


	//set solver tolerances
	flag = CVodeSStolerances(me->cvode_mem, reltol, abstol);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSStolerances: %d\n", flag);
		while(1);
	}

	//set root function
	flag = CVodeRootInit(me->cvode_mem, {{len $odeInit.GetInitialValues}}, ode_g);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeRootInit: %d\n", flag);
		while(1);
	}
}
{{else}}
int {{$block.Name}}_{{$alg.Name}}({{$block.Name}}_t *me) {
	//PROVIDED CODE: this algorithm was provided in an algorithm's text field
{{$alg.Other.Text}}

	return 0;
}
{{end}}
{{end}}
{{else}}//no algorithms were present for this function block
{{end}}

/* {{$block.Name}}_run() executes a single tick of an
 * instance of {{$block.Name}} according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void {{$block.Name}}_run({{$block.Name}}_t *me) {
	//if there are output events, reset them
	{{/*{{if $block.EventOutputs}}{{range $index, $count := count (add (div (len $block.EventOutputs.Events) 32) 1)}}me->outputEvents.events[{{$count}}] = 0;
	{{end}}{{end}}// this method seems to be having trouble on the t-crest SPM memory*/}}
	{{if $block.EventOutputs}}{{range $index, $event := $block.EventOutputs.Events}}me->outputEvents.event.{{$event.Name}} = 0;
	{{end}}{{end}}

	int odeRootFound; //used to trigger mid-tick transitions

restart:	//ode ECCs have ode setup states that aren't maintained for a tick, 
			//so they are passed through, so they need a place to goto 

repeat: 	//when we have had a mid-tick transition, we want to start the run again 
			
	me->_trigger = false;


	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		{{range $curStateIndex, $curState := $basicFB.States}}case STATE_{{$block.Name}}_{{$curState.Name}}:
			{{range $transIndex, $trans := $basicFB.GetTransitionsForState $curState.Name}}{{if $transIndex}}} else {{end}}if({{$cond := getCECCTransitionCondition $block $trans.Condition}}{{$cond.IfCond}}) {
				{{range $assEventIndex, $assEvent := $cond.AssEvents}}
				if({{$assEvent}}) { //events should cause no more than one transition, so due to possible mid-tick transitions in odeFBs we should consume events after we read them
					{{$assEvent}} = 0;
				}{{end}}
				me->_state = STATE_{{$block.Name}}_{{$trans.Destination}};
				me->_trigger = true;
			{{end}}{{if $basicFB.GetTransitionsForState $curState.Name}}};{{end}}
			break;
		{{end}}
		}
	}
	
	odeRootFound = 0;

	if(me->_trigger == true) {
		switch(me->_state) {
		{{range $curStateIndex, $curState := $basicFB.States}}case STATE_{{$block.Name}}_{{$curState.Name}}:
			{{range $actionIndex, $action := $curState.ECActions}}
			{{if algorithmNeedsCvodeInit (findAlgorithmFromName $basicFB $action.Algorithm)}}{{/*if this is calling an 
																ode initialisation algorithm we also need 
																pointers to the other ode, which means we need to know what state 
																this state goes to*/}}//init all ode algorithms that this state feeds into
			{{range $nextStateIndex, $nextState := nextPossibleECCStates $basicFB $curState}}{{range $nextActionIndex, $nextAction := $nextState.ECActions}}{{$nextAlg := findAlgorithmFromName $basicFB $nextAction.Algorithm}}{{if algorithmNeedsCvode $nextAlg}}{{$block.Name}}_{{$action.Algorithm}}(me, {{$block.Name}}_{{$nextAlg.Name}}_ode_f, {{$block.Name}}_{{$nextAlg.Name}}_ode_g);
			{{end}}{{end}}{{end}}{{else if $action.Algorithm}}{{/*this is normal algo call*/}}odeRootFound = {{$block.Name}}_{{$action.Algorithm}}(me);
			{{end}}{{if $action.Output}}me->outputEvents.event.{{$action.Output}} = 1;
			{{end}}{{end}}{{if stateIsCvodeSetup $basicFB $curState}}
			//this is an ODE setup state (ODE_init) so we need to repeat this whole function body
			goto restart;{{else}}
			if(odeRootFound == 1) {
				goto repeat;
			}{{end}}
			break;
		{{end}}
		}
	}
	
	printf("%f,%f,", me->Tcurr, me->Y);

}


{{end}}