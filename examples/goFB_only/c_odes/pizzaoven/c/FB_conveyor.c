// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the ODE / Hybrid Automata Function Block for conveyor
#include "FB_conveyor.h"


/* conveyor_preinit() is required to be called to 
 * initialise an instance of conveyor. 
 * It sets all I/O values to zero.
 */
int conveyor_preinit(conveyor_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.off = 0;
	me->inputEvents.event.on = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.xdchange = 0;
	
	//if there are input vars with default values, set them
	me->DeltaTime = 0.01;
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	me->_state = STATE_conveyor_Start;
	me->_trigger = true;
	
	me->cvode_mem = NULL;
	me->Tcurr = 0;
	me->Tnext = 0;
	me->T0 = 0;
	me->solveInProgress = 0;
	
	#ifdef PRINT_VALS
		printf("conveyor-x,");
		printf("conveyor-d,");
	
	#endif
	

	return 0;
}

/* conveyor_init() is required to be called to 
 * set up an instance of conveyor. 
 * It passes around configuration data.
 */
int conveyor_init(conveyor_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms


void conveyor_xPrimeEq0_dEq0(conveyor_t *me, CVRhsFn ode_f, CVRootFn ode_g) {
	//AUTOGENERATED CODE: this algorithm specifies the initialization of a CVODE SUNDIALS solver and was parsed from the algorithm's text field
	int flag;
	

	//free solver if it is initialized
	if(me->cvode_mem != NULL) {
		CVodeFree(&me->cvode_mem);
		N_VDestroy_Serial(me->ode_solution);  /* Free y vector */
	}

	//create solver
	me->ode_solution = N_VNew_Serial(1); //length of initial values
	me->cvode_mem = CVodeCreate(CV_ADAMS, CV_FUNCTIONAL);
	//me->cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON);
	if (me->cvode_mem == 0) {
		fprintf(stderr, "Error in CVodeMalloc: could not allocate\n");
		while(1);
	}

	//specify initial values
	
	NV_Ith_S(me->ode_solution, 0) = 0;
	
		
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

	CVodeSetNoInactiveRootWarn(me->cvode_mem); //make it so we don't get the annoying "root functino still identically zero" warnings

	//set solver tolerances
	flag = CVodeSStolerances(me->cvode_mem, REL_TOL, ABS_TOL);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSStolerances: %d\n", flag);
		while(1);
	}

	//set root function
	flag = CVodeRootInit(me->cvode_mem, 1, ode_g);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeRootInit: %d\n", flag);
		while(1);
	}
}



void conveyor_xPrimeEqx_dEqd(conveyor_t *me, CVRhsFn ode_f, CVRootFn ode_g) {
	//AUTOGENERATED CODE: this algorithm specifies the initialization of a CVODE SUNDIALS solver and was parsed from the algorithm's text field
	int flag;
	

	//free solver if it is initialized
	if(me->cvode_mem != NULL) {
		CVodeFree(&me->cvode_mem);
		N_VDestroy_Serial(me->ode_solution);  /* Free y vector */
	}

	//create solver
	me->ode_solution = N_VNew_Serial(1); //length of initial values
	me->cvode_mem = CVodeCreate(CV_ADAMS, CV_FUNCTIONAL);
	//me->cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON);
	if (me->cvode_mem == 0) {
		fprintf(stderr, "Error in CVodeMalloc: could not allocate\n");
		while(1);
	}

	//specify initial values
	
	NV_Ith_S(me->ode_solution, 0) = me->x;
	
		
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

	CVodeSetNoInactiveRootWarn(me->cvode_mem); //make it so we don't get the annoying "root functino still identically zero" warnings

	//set solver tolerances
	flag = CVodeSStolerances(me->cvode_mem, REL_TOL, ABS_TOL);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSStolerances: %d\n", flag);
		while(1);
	}

	//set root function
	flag = CVodeRootInit(me->cvode_mem, 1, ode_g);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeRootInit: %d\n", flag);
		while(1);
	}
}



static int conveyor_xDotEqXBy5_dEqdPlusx_ode_f(realtype t, N_Vector ode_solution, N_Vector ode_solution_dot, void *user_data) {
	//AUTOGENERATED CODE: this function represents the ODE in conveyor's xDotEqXBy5_dEqdPlusx algorithm
	//it is in a format that CVODE can process.
	conveyor_t *me = (conveyor_t*)user_data;
	
	NV_Ith_S(ode_solution_dot, 0) = NV_Ith_S(ode_solution, 0) / 5;
	
	return 0;
}

static int conveyor_xDotEqXBy5_dEqdPlusx_ode_g(realtype t, N_Vector ode_solution, realtype *gout, void *user_data) {
	//AUTOGENERATED CODE: this function represents the roots of the ODE in conveyor's xDotEqXBy5_dEqdPlusx algorithm
	//it is in a format that CVODE can process.
	
	gout[0] = NV_Ith_S(ode_solution, 0) - (0);
	
	return 0;
}

//return 1 if we found a root
int conveyor_xDotEqXBy5_dEqdPlusx(conveyor_t *me) {
	//AUTOGENERATED CODE: this function manages iterations of the ODE in conveyor's xDotEqXBy5_dEqdPlusx algorithm
	//It calls the CVODE solver and sets the outputs of the HA FB.
	if(me->solveInProgress == 0) {
		me->Tnext += me->DeltaTime;
		me->solveInProgress = 1; //solveInProgress is used to mark if we are currently solving
	}
	int flag = CVode(me->cvode_mem, me->Tnext, me->ode_solution, &me->Tcurr, CV_NORMAL); //CV_NORMAL
	if (flag < 0) {
		fprintf(stderr, "Error in CVode: %d\n", flag);
		while(1);
	} 
	
	
	me->x = NV_Ith_S(me->ode_solution, 0);
	
	me->d = me->d + me->x;
	

	if(flag == CV_ROOT_RETURN) {
		return 1;
	}

	me->solveInProgress = 0;
	return 0;
}




static int conveyor_xDotEqMminusxBy5_dEqdPlusx_ode_f(realtype t, N_Vector ode_solution, N_Vector ode_solution_dot, void *user_data) {
	//AUTOGENERATED CODE: this function represents the ODE in conveyor's xDotEqMminusxBy5_dEqdPlusx algorithm
	//it is in a format that CVODE can process.
	conveyor_t *me = (conveyor_t*)user_data;
	
	NV_Ith_S(ode_solution_dot, 0) = (0.02 - NV_Ith_S(ode_solution, 0)) / 5;
	
	return 0;
}

static int conveyor_xDotEqMminusxBy5_dEqdPlusx_ode_g(realtype t, N_Vector ode_solution, realtype *gout, void *user_data) {
	//AUTOGENERATED CODE: this function represents the roots of the ODE in conveyor's xDotEqMminusxBy5_dEqdPlusx algorithm
	//it is in a format that CVODE can process.
	
	gout[0] = NV_Ith_S(ode_solution, 0) - (0);
	
	return 0;
}

//return 1 if we found a root
int conveyor_xDotEqMminusxBy5_dEqdPlusx(conveyor_t *me) {
	//AUTOGENERATED CODE: this function manages iterations of the ODE in conveyor's xDotEqMminusxBy5_dEqdPlusx algorithm
	//It calls the CVODE solver and sets the outputs of the HA FB.
	if(me->solveInProgress == 0) {
		me->Tnext += me->DeltaTime;
		me->solveInProgress = 1; //solveInProgress is used to mark if we are currently solving
	}
	int flag = CVode(me->cvode_mem, me->Tnext, me->ode_solution, &me->Tcurr, CV_NORMAL); //CV_NORMAL
	if (flag < 0) {
		fprintf(stderr, "Error in CVode: %d\n", flag);
		while(1);
	} 
	
	
	me->x = NV_Ith_S(me->ode_solution, 0);
	
	me->d = me->d + me->x;
	

	if(flag == CV_ROOT_RETURN) {
		return 1;
	}

	me->solveInProgress = 0;
	return 0;
}





/* conveyor_run() executes a single tick of an
 * instance of conveyor according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void conveyor_run(conveyor_t *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.xdchange = 0;
	

	int odeRootFound; //used to trigger mid-tick transitions

restart:	//ode ECCs have ode setup states that aren't maintained for a tick, 
			//so they are passed through, so they need a place to goto 

repeat: 	//when we have had a mid-tick transition, we want to start the run again 
			
	me->_trigger = false;


	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_conveyor_Start:
			if(true) {
				
				me->_state = STATE_conveyor_offE0;
				me->_trigger = true;
			};
			break;
		case STATE_conveyor_offE0:
			if(me->inputEvents.event.on) {
				
				if(me->inputEvents.event.on) { //events should cause no more than one transition, so due to possible mid-tick transitions in odeFBs we should consume events after we read them
					me->inputEvents.event.on = 0;
				}
				me->_state = STATE_conveyor_onE0;
				me->_trigger = true;
			} else if(true) {
				
				me->_state = STATE_conveyor_off;
				me->_trigger = true;
			};
			break;
		case STATE_conveyor_off:
			if(me->inputEvents.event.on) {
				
				if(me->inputEvents.event.on) { //events should cause no more than one transition, so due to possible mid-tick transitions in odeFBs we should consume events after we read them
					me->inputEvents.event.on = 0;
				}
				me->_state = STATE_conveyor_onE0;
				me->_trigger = true;
			} else if(true) {
				
				me->_state = STATE_conveyor_off;
				me->_trigger = true;
			};
			break;
		case STATE_conveyor_onE0:
			if(me->inputEvents.event.off) {
				
				if(me->inputEvents.event.off) { //events should cause no more than one transition, so due to possible mid-tick transitions in odeFBs we should consume events after we read them
					me->inputEvents.event.off = 0;
				}
				me->_state = STATE_conveyor_offE1;
				me->_trigger = true;
			} else if(true) {
				
				me->_state = STATE_conveyor_on;
				me->_trigger = true;
			};
			break;
		case STATE_conveyor_on:
			if(me->inputEvents.event.off) {
				
				if(me->inputEvents.event.off) { //events should cause no more than one transition, so due to possible mid-tick transitions in odeFBs we should consume events after we read them
					me->inputEvents.event.off = 0;
				}
				me->_state = STATE_conveyor_offE1;
				me->_trigger = true;
			} else if(true) {
				
				me->_state = STATE_conveyor_on;
				me->_trigger = true;
			};
			break;
		case STATE_conveyor_offE1:
			if(me->inputEvents.event.on) {
				
				if(me->inputEvents.event.on) { //events should cause no more than one transition, so due to possible mid-tick transitions in odeFBs we should consume events after we read them
					me->inputEvents.event.on = 0;
				}
				me->_state = STATE_conveyor_onE0;
				me->_trigger = true;
			} else if(true) {
				
				me->_state = STATE_conveyor_off;
				me->_trigger = true;
			};
			break;
		
		}
	}
	
	odeRootFound = 0;

	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_conveyor_Start:
			
			if(odeRootFound == 1) {
				me->solveInProgress=0;me->Tcurr = me->Tnext;
			}
			break;
		case STATE_conveyor_offE0:
			
			//init all ode algorithms that this state feeds into
			conveyor_xPrimeEq0_dEq0(me, conveyor_xDotEqXBy5_dEqdPlusx_ode_f, conveyor_xDotEqXBy5_dEqdPlusx_ode_g);
			me->outputEvents.event.xdchange = 1;
			
			odeRootFound = conveyor_xDotEqXBy5_dEqdPlusx(me);
			
			//this is an ODE setup state (ODE_init) so we need to repeat this whole function body
			/*goto restart; this is currently disabled because we don't need it when running non-optimised versions of code*/
			if(odeRootFound == 1) {
				me->solveInProgress=0;me->Tcurr = me->Tnext;
			}
			break;
		case STATE_conveyor_off:
			
			odeRootFound = conveyor_xDotEqXBy5_dEqdPlusx(me);
			me->outputEvents.event.xdchange = 1;
			
			if(odeRootFound == 1) {
				me->solveInProgress=0;me->Tcurr = me->Tnext;
			}
			break;
		case STATE_conveyor_onE0:
			
			//init all ode algorithms that this state feeds into
			conveyor_xPrimeEqx_dEqd(me, conveyor_xDotEqMminusxBy5_dEqdPlusx_ode_f, conveyor_xDotEqMminusxBy5_dEqdPlusx_ode_g);
			me->outputEvents.event.xdchange = 1;
			
			odeRootFound = conveyor_xDotEqMminusxBy5_dEqdPlusx(me);
			
			//this is an ODE setup state (ODE_init) so we need to repeat this whole function body
			/*goto restart; this is currently disabled because we don't need it when running non-optimised versions of code*/
			if(odeRootFound == 1) {
				me->solveInProgress=0;me->Tcurr = me->Tnext;
			}
			break;
		case STATE_conveyor_on:
			
			odeRootFound = conveyor_xDotEqMminusxBy5_dEqdPlusx(me);
			me->outputEvents.event.xdchange = 1;
			
			if(odeRootFound == 1) {
				me->solveInProgress=0;me->Tcurr = me->Tnext;
			}
			break;
		case STATE_conveyor_offE1:
			
			//init all ode algorithms that this state feeds into
			conveyor_xPrimeEqx_dEqd(me, conveyor_xDotEqXBy5_dEqdPlusx_ode_f, conveyor_xDotEqXBy5_dEqdPlusx_ode_g);
			me->outputEvents.event.xdchange = 1;
			
			odeRootFound = conveyor_xDotEqXBy5_dEqdPlusx(me);
			
			//this is an ODE setup state (ODE_init) so we need to repeat this whole function body
			/*goto restart; this is currently disabled because we don't need it when running non-optimised versions of code*/
			if(odeRootFound == 1) {
				me->solveInProgress=0;me->Tcurr = me->Tnext;
			}
			break;
		
		}
	}

	#ifdef PRINT_VALS
	
		printf("%f,", me->x);
	
		printf("%f,", me->d);
	 
	#endif

}


