// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for TickGen
#include "TickGen.h"


/* TickGen_preinit() is required to be called to 
 * initialise an instance of TickGen. 
 * It sets all I/O values to zero.
 */
int TickGen_preinit(TickGen_t  *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	me->outputEvents.event.Tick = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	me->_state = STATE_TickGen_Start;
	me->_trigger = true;
	
	
	
	
	return 0;
}

/* TickGen_init() is required to be called to 
 * set up an instance of TickGen. 
 * It passes around configuration data.
 */
int TickGen_init(TickGen_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void TickGen_setup_algo(TickGen_t  *me) {
//PROVIDED CODE: this algorithm was provided in an algorithm's text field
me->DeltaTime = me->SetDeltaTime;
}



/* TickGen_run() executes a single tick of an
 * instance of TickGen according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void TickGen_run(TickGen_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.Tick = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_TickGen_Start:
			if(true) {
				me->_state = STATE_TickGen_setup;
				me->_trigger = true;
			};
			break;
		case STATE_TickGen_setup:
			if(true) {
				me->_state = STATE_TickGen_emit;
				me->_trigger = true;
			};
			break;
		case STATE_TickGen_emit:
			if(true) {
				me->_state = STATE_TickGen_emit;
				me->_trigger = true;
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_TickGen_Start:
			break;

		case STATE_TickGen_setup:
			TickGen_setup_algo(me);
			break;

		case STATE_TickGen_emit:
			me->outputEvents.event.Tick = 1;
			break;

		
		}
	}

	me->_trigger = false;
}


