// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for ConveyorController
#include "ConveyorController.h"


/* ConveyorController_preinit() is required to be called to 
 * initialise an instance of ConveyorController. 
 * It sets all I/O values to zero.
 */
int ConveyorController_preinit(ConveyorController_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.InjectDone = 0;
	me->inputEvents.event.EmergencyStopChanged = 0;
	me->inputEvents.event.LasersChanged = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.ConveyorChanged = 0;
	me->outputEvents.event.ConveyorStoppedForInject = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_ConveyorController_E_Stop;
	

	return 0;
}

/* ConveyorController_init() is required to be called to 
 * set up an instance of ConveyorController. 
 * It passes around configuration data.
 */
int ConveyorController_init(ConveyorController_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void ConveyorController_ConveyorStart(ConveyorController_t  *me) {
me->ConveyorSpeed = 1;
//printf("Conveyor: Start\n");
}

void ConveyorController_ConveyorStop(ConveyorController_t  *me) {
me->ConveyorSpeed = 0;
//printf("Conveyor: Stop\n");
}

void ConveyorController_ConveyorRunning(ConveyorController_t  *me) {
//printf("Conveyor running region\n");
}

void ConveyorController_ConveyorEStop(ConveyorController_t  *me) {
//printf("Conveyor Emergency Stopped\n");
}



/* ConveyorController_run() executes a single tick of an
 * instance of ConveyorController according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void ConveyorController_run(ConveyorController_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.ConveyorChanged = 0;
	me->outputEvents.event.ConveyorStoppedForInject = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_ConveyorController_E_Stop:
			if(me->inputEvents.event.EmergencyStopChanged && ( ! me->EmergencyStop)) {
				me->_state = STATE_ConveyorController_Running;
				me->_trigger = true;
				
			};
			break;
		case STATE_ConveyorController_Running:
			if(me->inputEvents.event.LasersChanged && (me->InjectSiteLaser)) {
				me->_state = STATE_ConveyorController_Pause;
				me->_trigger = true;
				
			};
			break;
		case STATE_ConveyorController_Pause:
			if(me->inputEvents.event.InjectDone) {
				me->_state = STATE_ConveyorController_Running;
				me->_trigger = true;
				
			} else if(me->inputEvents.event.EmergencyStopChanged && (me->EmergencyStop)) {
				me->_state = STATE_ConveyorController_E_Stop;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_ConveyorController_E_Stop:
			break;

		case STATE_ConveyorController_Running:
			ConveyorController_ConveyorStart(me);
			me->outputEvents.event.ConveyorChanged = 1;
			break;

		case STATE_ConveyorController_Pause:
			ConveyorController_ConveyorStop(me);
			me->outputEvents.event.ConveyorChanged = 1;
			me->outputEvents.event.ConveyorStoppedForInject = 1;
			break;

		
		}
	}

	me->_trigger = false;
}

