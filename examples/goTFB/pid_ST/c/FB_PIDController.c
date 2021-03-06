// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for PIDController
#include "FB_PIDController.h"


/* PIDController_preinit() is required to be called to 
 * initialise an instance of PIDController. 
 * It sets all I/O values to zero.
 */
int PIDController_preinit(PIDController_t  *me) {
	

	//reset the input events
	me->inputEvents.event.UpdateConfig = 0;
	//reset the input events
	me->inputEvents.event.Reset = 0;
	//reset the input events
	me->inputEvents.event.Tick = 0;
	
	//reset the output events
	me->outputEvents.event.ControlChanged = 0;
	
	//set any input vars with default values
	
	//set any output vars with default values
	
	//set any internal vars with default values
	
	
	
	
	

	
	
	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	me->_state = STATE_PIDController_start;
	me->_trigger = true;
	
	
	

	return 0;
}

/* PIDController_init() is required to be called to 
 * set up an instance of PIDController. 
 * It passes around configuration data.
 */
int PIDController_init(PIDController_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	
	

	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void PIDController_PIDTick(PIDController_t  *me) {
//PROVIDED CODE: this algorithm was provided in an algorithm's text field
me->currentError = me->DesiredValue - me->CurrentValue;
me->integrationError = me->integrationError + me->currentError;
if(me->integrationError < -me->WindupGuard) {
			me->integrationError = -me->WindupGuard;

		} else if(me->integrationError > me->WindupGuard) {
			me->integrationError = me->WindupGuard;

		}me->differentialError = me->currentError - me->previousError;
me->pTerm = me->PGain * me->currentError;
me->iTerm = me->IGain * me->integrationError;
me->dTerm = me->DGain * me->differentialError;
me->ControlValue = me->pTerm + me->iTerm + me->dTerm;
me->previousError = me->currentError;

}

void PIDController_PIDZero(PIDController_t  *me) {
//PROVIDED CODE: this algorithm was provided in an algorithm's text field
me->previousError = 0;
me->integrationError = 0;

}



/* PIDController_run() executes a single tick of an
 * instance of PIDController according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will already be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void PIDController_run(PIDController_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.ControlChanged = 0;
	
	
	

	
	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_PIDController_start:
			if(true) {
				
				me->_state = STATE_PIDController_reset;
				me->_trigger = true;
			};
			break;
		case STATE_PIDController_update:
			if(me->inputEvents.event.Reset) {
				
				me->_state = STATE_PIDController_reset;
				me->_trigger = true;
			} else if(me->inputEvents.event.Tick) {
				
				me->_state = STATE_PIDController_update;
				me->_trigger = true;
			};
			break;
		case STATE_PIDController_reset:
			if(me->inputEvents.event.Reset) {
				
				me->_state = STATE_PIDController_reset;
				me->_trigger = true;
			} else if(me->inputEvents.event.Tick) {
				
				me->_state = STATE_PIDController_update;
				me->_trigger = true;
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_PIDController_start:
			#ifdef PRINT_STATES
				printf("PIDController: [Entered State start]\n");
			#endif
			
			break;

		case STATE_PIDController_update:
			#ifdef PRINT_STATES
				printf("PIDController: [Entered State update]\n");
			#endif
			me->outputEvents.event.ControlChanged = 1;
			PIDController_PIDTick(me);
			
			break;

		case STATE_PIDController_reset:
			#ifdef PRINT_STATES
				printf("PIDController: [Entered State reset]\n");
			#endif
			PIDController_PIDZero(me);
			
			break;

		
		}
	}

	me->_trigger = false;

	

	//Ensure input events are cleared
	me->inputEvents.event.UpdateConfig = 0;
	me->inputEvents.event.Reset = 0;
	me->inputEvents.event.Tick = 0;
	
}


