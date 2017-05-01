// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for InjectorPumpsController
#include "InjectorPumpsController.h"


/* InjectorPumpsController_preinit() is required to be called to 
 * initialise an instance of InjectorPumpsController. 
 * It sets all I/O values to zero.
 */
int InjectorPumpsController_preinit(InjectorPumpsController_t _SPM *me) {
	//if there are input events, reset them
	me->inputEvents.event.StartPump = 0;
	me->inputEvents.event.EmergencyStopChanged = 0;
	me->inputEvents.event.CanisterPressureChanged = 0;
	me->inputEvents.event.FillContentsAvailableChanged = 0;
	me->inputEvents.event.VacuumTimerElapsed = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.PumpFinished = 0;
	me->outputEvents.event.RejectCanister = 0;
	me->outputEvents.event.InjectorControlsChanged = 0;
	me->outputEvents.event.FillContentsChanged = 0;
	me->outputEvents.event.StartVacuumTimer = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_InjectorPumpsController_RejectCanister;
	

	return 0;
}

/* InjectorPumpsController_init() is required to be called to 
 * set up an instance of InjectorPumpsController. 
 * It passes around configuration data.
 */
int InjectorPumpsController_init(InjectorPumpsController_t _SPM *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void InjectorPumpsController_StartVacuum(InjectorPumpsController_t _SPM *me) {
me->InjectorVacuumRun = 1;
//printf("Injector: Start vacuum\n");
}

void InjectorPumpsController_ClearControls(InjectorPumpsController_t _SPM *me) {
me->InjectorContentsValveOpen = 0;
me->InjectorPressurePumpRun = 0;
me->InjectorVacuumRun = 0;
//printf("Injector: Clear controls\n");
}

void InjectorPumpsController_OpenValve(InjectorPumpsController_t _SPM *me) {
me->InjectorContentsValveOpen = 1;
//printf("Injector: Open valve\n");
}

void InjectorPumpsController_StartPump(InjectorPumpsController_t _SPM *me) {
me->InjectorPressurePumpRun = 1;
//printf("Injector: Start pump\n");
}



/* InjectorPumpsController_run() executes a single tick of an
 * instance of InjectorPumpsController according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void InjectorPumpsController_run(InjectorPumpsController_t _SPM *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.PumpFinished = 0;
	me->outputEvents.event.RejectCanister = 0;
	me->outputEvents.event.InjectorControlsChanged = 0;
	me->outputEvents.event.FillContentsChanged = 0;
	me->outputEvents.event.StartVacuumTimer = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_InjectorPumpsController_RejectCanister:
			if(true) {
				me->_state = STATE_InjectorPumpsController_AwaitPump;
				me->_trigger = true;
				
			};
			break;
		case STATE_InjectorPumpsController_AwaitPump:
			if(me->inputEvents.event.StartPump) {
				me->_state = STATE_InjectorPumpsController_VacuumPump;
				me->_trigger = true;
				
			};
			break;
		case STATE_InjectorPumpsController_VacuumPump:
			if(me->inputEvents.event.VacuumTimerElapsed) {
				me->_state = STATE_InjectorPumpsController_RejectCanister;
				me->_trigger = true;
				
			} else if(me->inputEvents.event.CanisterPressureChanged && (me->CanisterPressure <= 10)) {
				me->_state = STATE_InjectorPumpsController_StopVacuum;
				me->_trigger = true;
				
			};
			break;
		case STATE_InjectorPumpsController_FinishPump:
			if(true) {
				me->_state = STATE_InjectorPumpsController_AwaitPump;
				me->_trigger = true;
				
			};
			break;
		case STATE_InjectorPumpsController_StartPump:
			if(me->inputEvents.event.CanisterPressureChanged && (me->CanisterPressure >= 245)) {
				me->_state = STATE_InjectorPumpsController_FinishPump;
				me->_trigger = true;
				
			};
			break;
		case STATE_InjectorPumpsController_OpenValve:
			if(true) {
				me->_state = STATE_InjectorPumpsController_StartPump;
				me->_trigger = true;
				
			};
			break;
		case STATE_InjectorPumpsController_StopVacuum:
			if(true) {
				me->_state = STATE_InjectorPumpsController_OpenValve;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_InjectorPumpsController_RejectCanister:
			InjectorPumpsController_ClearControls(me);
			me->outputEvents.event.RejectCanister = 1;
			me->outputEvents.event.InjectorControlsChanged = 1;
			break;

		case STATE_InjectorPumpsController_AwaitPump:
			me->outputEvents.event.PumpFinished = 1;
			break;

		case STATE_InjectorPumpsController_VacuumPump:
			InjectorPumpsController_StartVacuum(me);
			me->outputEvents.event.InjectorControlsChanged = 1;
			me->outputEvents.event.StartVacuumTimer = 1;
			break;

		case STATE_InjectorPumpsController_FinishPump:
			InjectorPumpsController_ClearControls(me);
			me->outputEvents.event.InjectorControlsChanged = 1;
			break;

		case STATE_InjectorPumpsController_StartPump:
			InjectorPumpsController_StartPump(me);
			me->outputEvents.event.InjectorControlsChanged = 1;
			break;

		case STATE_InjectorPumpsController_OpenValve:
			InjectorPumpsController_OpenValve(me);
			me->outputEvents.event.InjectorControlsChanged = 1;
			break;

		case STATE_InjectorPumpsController_StopVacuum:
			InjectorPumpsController_ClearControls(me);
			me->outputEvents.event.InjectorControlsChanged = 1;
			break;

		
		}
	}

	me->_trigger = false;
}

