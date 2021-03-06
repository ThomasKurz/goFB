// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for SawmillPosGen
#include "SawmillPosGen.h"


/* SawmillPosGen_preinit() is required to be called to 
 * initialise an instance of SawmillPosGen. 
 * It sets all I/O values to zero.
 */
int SawmillPosGen_preinit(SawmillPosGen_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.SawRunChange = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.NewPosChange = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	me->PosArrayLen = 20;
	me->PosArrayPos = 0;
	me->PosArray[0] = 0;
	me->PosArray[1] = 0.5;
	me->PosArray[2] = 1;
	me->PosArray[3] = 1.5;
	me->PosArray[4] = 2;
	me->PosArray[5] = 2.5;
	me->PosArray[6] = 3;
	me->PosArray[7] = 3.5;
	me->PosArray[8] = 4;
	me->PosArray[9] = 4.5;
	me->PosArray[10] = 5;
	me->PosArray[11] = 4.5;
	me->PosArray[12] = 4;
	me->PosArray[13] = 3.5;
	me->PosArray[14] = 3;
	me->PosArray[15] = 2.5;
	me->PosArray[16] = 2;
	me->PosArray[17] = 1.5;
	me->PosArray[18] = 1;
	me->PosArray[19] = 0.5;
	me->BusyWork = 0;
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_SawmillPosGen_Start;
	

	return 0;
}

/* SawmillPosGen_init() is required to be called to 
 * set up an instance of SawmillPosGen. 
 * It passes around configuration data.
 */
int SawmillPosGen_init(SawmillPosGen_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



/* SawmillPosGen_run() executes a single tick of an
 * instance of SawmillPosGen according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void SawmillPosGen_run(SawmillPosGen_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.NewPosChange = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_SawmillPosGen_Start:
			if(true) {
				me->_state = STATE_SawmillPosGen_run;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillPosGen_run:
			if(true) {
				me->_state = STATE_SawmillPosGen_run;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_SawmillPosGen_Start:
			break;

		case STATE_SawmillPosGen_run:
			SawmillPosGen_posgen_service(me);
			break;

		
		}
	}

	me->_trigger = false;
}
//algorithms

void SawmillPosGen_posgen_service(SawmillPosGen_t  *me) {

if(me->SawRun) {
	me->outputEvents.event.NewPosChange = 1;
	me->NewPos = me->PosArray[me->PosArrayPos];
	me->PosArrayPos++;
	me->PosArrayPos = me->PosArrayPos % me->PosArrayLen;
} else {
	me->outputEvents.event.NewPosChange = 0;
}
}



