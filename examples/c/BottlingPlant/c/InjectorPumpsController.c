// This file has been automatically generated by go-iec61499 and should not be edited by hand
// Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499

// This file represents the implementation of the Basic Function Block for InjectorPumpsController
#include "InjectorPumpsController.h"

enum InjectorPumpsController_states { STATE_RejectCanister, STATE_AwaitPump, STATE_VacuumPump, STATE_FinishPump, STATE_StartPump, STATE_OpenValve, STATE_StopVacuum };

/* InjectorPumpsController_init() is required to be called to 
 * initialise an instance of InjectorPumpsController. 
 * It sets all I/O values to zero.
 */
void InjectorPumpsController_init(struct InjectorPumpsController *me) {
	//if there are input events, reset them
	me->inputEvents.events[0] = 0;
	
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//if there are input vars, reset them
	me->EmergencyStop = 0;
	me->CanisterPressure = 0;
	me->FillContentsAvailable = 0;
	
	//if there are output vars, reset them
	me->InjectorContentsValveOpen = 0;
	me->InjectorVacuumRun = 0;
	me->InjectorPressurePumpRun = 0;
	me->FillContents = 0;
	
	//if there are internal vars, reset them
	
}

/* InjectorPumpsController_run() executes a single tick of an
 * instance of InjectorPumpsController according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 */
void InjectorPumpsController_run(struct InjectorPumpsController *me) {
	//current state storage
	static enum InjectorPumpsController_states state = STATE_RejectCanister;
	static BOOL trigger = true; //should be true the first time this is run

	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//now, let's advance state
	switch(state) {
	case STATE_RejectCanister:
		if(true) {
			state = STATE_AwaitPump;
			trigger = true;
		};
		break;

	case STATE_AwaitPump:
		if(me->inputEvents.event.StartPump) {
			state = STATE_VacuumPump;
			trigger = true;
		};
		break;

	case STATE_VacuumPump:
		if(me->inputEvents.event.VacuumTimerElapsed) {
			state = STATE_RejectCanister;
			trigger = true;
		} else if(me->inputEvents.event.CanisterPressureChanged && (me->CanisterPressure <= 10)) {
			state = STATE_StopVacuum;
			trigger = true;
		};
		break;

	case STATE_FinishPump:
		if(true) {
			state = STATE_AwaitPump;
			trigger = true;
		};
		break;

	case STATE_StartPump:
		if(me->inputEvents.event.CanisterPressureChanged && (me->CanisterPressure >= 245)) {
			state = STATE_FinishPump;
			trigger = true;
		};
		break;

	case STATE_OpenValve:
		if(true) {
			state = STATE_StartPump;
			trigger = true;
		};
		break;

	case STATE_StopVacuum:
		if(true) {
			state = STATE_OpenValve;
			trigger = true;
		};
		break;

	
	}

	//now, let's run any algorithms and emit any events that need to occur due to the trigger
	if(trigger == true) {
		switch(state) {
		case STATE_RejectCanister:
			InjectorPumpsController_ClearControls(me);
			me->outputEvents.event.RejectCanister = 1;
			me->outputEvents.event.InjectorControlsChanged = 1;
			break;

		case STATE_AwaitPump:
			me->outputEvents.event.PumpFinished = 1;
			break;

		case STATE_VacuumPump:
			InjectorPumpsController_StartVacuum(me);
			me->outputEvents.event.InjectorControlsChanged = 1;
			me->outputEvents.event.StartVacuumTimer = 1;
			break;

		case STATE_FinishPump:
			InjectorPumpsController_ClearControls(me);
			me->outputEvents.event.InjectorControlsChanged = 1;
			break;

		case STATE_StartPump:
			InjectorPumpsController_StartPump(me);
			me->outputEvents.event.InjectorControlsChanged = 1;
			break;

		case STATE_OpenValve:
			InjectorPumpsController_OpenValve(me);
			me->outputEvents.event.InjectorControlsChanged = 1;
			break;

		case STATE_StopVacuum:
			InjectorPumpsController_ClearControls(me);
			me->outputEvents.event.InjectorControlsChanged = 1;
			break;

		
		}
	}

	trigger = false;
}

//algorithms

void InjectorPumpsController_StartVacuum(struct InjectorPumpsController *me) {
me->InjectorVacuumRun = 1;
//printf("Injector: Start vacuum\n");
}

void InjectorPumpsController_ClearControls(struct InjectorPumpsController *me) {
me->InjectorContentsValveOpen = 0;
me->InjectorPressurePumpRun = 0;
me->InjectorVacuumRun = 0;
//printf("Injector: Clear controls\n");
}

void InjectorPumpsController_OpenValve(struct InjectorPumpsController *me) {
me->InjectorContentsValveOpen = 1;
//printf("Injector: Open valve\n");
}

void InjectorPumpsController_StartPump(struct InjectorPumpsController *me) {
me->InjectorPressurePumpRun = 1;
//printf("Injector: Start pump\n");
}


