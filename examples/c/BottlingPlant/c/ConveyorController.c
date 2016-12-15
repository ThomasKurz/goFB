// This file has been automatically generated by go-iec61499 and should not be edited by hand
// Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499

// This file represents the implementation of the Basic Function Block for ConveyorController
#include "ConveyorController.h"

enum ConveyorController_states { STATE_E_Stop, STATE_Running, STATE_Pause };

/* ConveyorController_init() is required to be called to 
 * initialise an instance of ConveyorController. 
 * It sets all I/O values to zero.
 */
void ConveyorController_init(struct ConveyorController *me) {
	//if there are input events, reset them
	me->inputEvents.events[0] = 0;
	
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//if there are input vars, reset them
	me->EmergencyStop = 0;
	me->InjectSiteLaser = 0;
	
	//if there are output vars, reset them
	me->ConveyorSpeed = 0;
	
	//if there are internal vars, reset them
	me->Variable1 = 0;
	
}

/* ConveyorController_run() executes a single tick of an
 * instance of ConveyorController according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 */
void ConveyorController_run(struct ConveyorController *me) {
	//current state storage
	static enum ConveyorController_states state = STATE_E_Stop;
	static BOOL trigger = true; //should be true the first time this is run

	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//now, let's advance state
	switch(state) {
	case STATE_E_Stop:
		if(me->inputEvents.event.EmergencyStopChanged && (!me->EmergencyStop)) {
			state = STATE_Running;
			trigger = true;
		};
		break;

	case STATE_Running:
		if(me->inputEvents.event.LasersChanged && (me->InjectSiteLaser)) {
			state = STATE_Pause;
			trigger = true;
		};
		break;

	case STATE_Pause:
		if(me->inputEvents.event.InjectDone) {
			state = STATE_Running;
			trigger = true;
		} else if(me->inputEvents.event.EmergencyStopChanged && (me->EmergencyStop)) {
			state = STATE_E_Stop;
			trigger = true;
		};
		break;

	
	}

	//now, let's run any algorithms and emit any events that need to occur due to the trigger
	if(trigger == true) {
		switch(state) {
		case STATE_E_Stop:
			break;

		case STATE_Running:
			ConveyorController_ConveyorStart(me);
			me->outputEvents.event.ConveyorChanged = 1;
			break;

		case STATE_Pause:
			ConveyorController_ConveyorStop(me);
			me->outputEvents.event.ConveyorChanged = 1;
			me->outputEvents.event.ConveyorStoppedForInject = 1;
			break;

		
		}
	}

	trigger = false;
}

//algorithms

void ConveyorController_ConveyorStart(struct ConveyorController *me) {
me->ConveyorSpeed = 1;
printf("Conveyor: Start\n");
}

void ConveyorController_ConveyorStop(struct ConveyorController *me) {
me->ConveyorSpeed = 0;
printf("Conveyor: Stop\n");
}

void ConveyorController_ConveyorRunning(struct ConveyorController *me) {
printf("Conveyor running region\n");
}

void ConveyorController_ConveyorEStop(struct ConveyorController *me) {
printf("Conveyor Emergency Stopped\n");
}


