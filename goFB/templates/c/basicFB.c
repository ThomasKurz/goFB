{{define "basicFB"}}// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB
{{$block := index .Blocks .BlockIndex}}{{$blocks := .Blocks}}{{$basicFB := $block.BasicFB}}{{$tcrestUsingSPM := .TcrestUsingSPM}}{{$tcrestSmartSPM := .TcrestSmartSPM}}{{$runOnECC := .RunOnECC}}{{$eventQueue := .EventQueue}}
// This file represents the implementation of the Basic Function Block for {{$block.Name}}
#include "FB_{{$block.Name}}.h"

{{template "_fbinit" .}}

{{if $basicFB.Algorithms}}//algorithms
{{range $algIndex, $alg := $basicFB.Algorithms}}
void {{$block.Name}}_{{$alg.Name}}({{$block.Name}}_t {{if or $tcrestUsingSPM $tcrestSmartSPM}}_SPM{{end}} *me) {
//PROVIDED CODE: this algorithm was provided in an algorithm's text field
{{compileAlgorithm $block $alg}}
}
{{end}}
{{else}}//no algorithms were present for this function block
{{end}}

/* {{$block.Name}}_run() executes a single tick of an
 * instance of {{$block.Name}} according to {{if $eventQueue}}event-driven{{else}}synchronous{{end}} semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will already be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void {{$block.Name}}_run({{$block.Name}}_t {{if or $tcrestUsingSPM $tcrestSmartSPM}}_SPM{{end}} *me) {
	//if there are output events, reset them
	{{/*{{if $block.EventOutputs}}{{range $index, $count := count (add (div (len $block.EventOutputs.Events) 32) 1)}}me->outputEvents.events[{{$count}}] = 0;
	{{end}}{{end}}// this method seems to be having trouble on the t-crest SPM memory*/}}
	{{if $block.EventOutputs}}{{range $index, $event := $block.EventOutputs}}me->outputEvents.event.{{$event.Name}} = 0;
	{{end}}{{end}}

	{{if $runOnECC}}
{{$block.Name}}_runOn:{{end}}
	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		{{range $curStateIndex, $curState := $basicFB.States}}case STATE_{{$block.Name}}_{{$curState.Name}}:
			{{range $transIndex, $trans := $basicFB.GetTransitionsForState $curState.Name}}{{if $transIndex}}} else {{end}}if({{$cond := getCECCTransitionCondition $block $trans.Condition}}{{$cond.IfCond}}) {
				{{if $runOnECC}}{{range $assEventIndex, $assEvent := $cond.AssEvents}}
					if({{$assEvent}}) {
						//in the event-driven MoC (standards compliant with IEC61499 second revision), events can only be consumed once
						{{$assEvent}} = 0;
					}
				{{end}}{{end}}
				me->_state = STATE_{{$block.Name}}_{{$trans.Destination}};
				me->_trigger = true;
			{{end}}{{if $basicFB.GetTransitionsForState $curState.Name}}};{{end}}
			break;
		{{end}}
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		{{range $curStateIndex, $curState := $basicFB.States}}case STATE_{{$block.Name}}_{{$curState.Name}}:
			#ifdef PRINT_STATES
				printf("{{$block.Name}}: [Entered State {{$curState.Name}}]\n");
			#endif
			{{range $actionIndex, $action := $curState.ECActions}}{{if $action.Algorithm}}{{$block.Name}}_{{$action.Algorithm}}(me);
			{{end}}{{if $action.Output}}{{if $eventQueue}}PushEvent(me->myInstanceID, {{getOutputEventPortID $block $action.Output}}); /*i'm emitting {{$action.Output}}*/{{else}}me->outputEvents.event.{{$action.Output}} = 1;{{end}}
			{{end}}{{end}}
			{{if $runOnECC}}me->_trigger = false;
			goto {{$block.Name}}_runOn;
			{{end}}break;

		{{end}}
		}
	}

	me->_trigger = false;

	//Ensure input events are cleared
	{{if $block.EventInputs}}{{range $index, $event := $block.EventInputs}}me->inputEvents.event.{{$event.Name}} = 0;
	{{end}}{{end}}
}


{{end}}