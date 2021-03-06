// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for BfbGen
#include "FB_BfbGen.h"


/* BfbGen_preinit() is required to be called to 
 * initialise an instance of BfbGen. 
 * It sets all I/O values to zero.
 */
int BfbGen_preinit(BfbGen_t  *me) {
	

	
	//reset the output events
	me->outputEvents.event.genE = 0;
	
	//set any input vars with default values
	
	//set any output vars with default values
	me->genDat = 1;
	
	//set any internal vars with default values
	
	
	
	
	

	
	
	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	me->_state = STATE_BfbGen_start;
	me->_trigger = true;
	
	
	

	return 0;
}

/* BfbGen_init() is required to be called to 
 * set up an instance of BfbGen. 
 * It passes around configuration data.
 */
int BfbGen_init(BfbGen_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	
	

	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void BfbGen_run_alg0(BfbGen_t  *me) {
//PROVIDED CODE: this algorithm was provided in an algorithm's text field
me->genDat = me->genDat + 1;

}



/* BfbGen_run() executes a single tick of an
 * instance of BfbGen according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will already be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void BfbGen_run(BfbGen_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.genE = 0;
	

	
	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_BfbGen_start:
			if(true) {
				
				me->_state = STATE_BfbGen_run;
				me->_trigger = true;
			};
			break;
		case STATE_BfbGen_run:
			if(true) {
				
				me->_state = STATE_BfbGen_run;
				me->_trigger = true;
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_BfbGen_start:
			#ifdef PRINT_STATES
				printf("BfbGen: [Entered State start]\n");
			#endif
			
			break;

		case STATE_BfbGen_run:
			#ifdef PRINT_STATES
				printf("BfbGen: [Entered State run]\n");
			#endif
			me->outputEvents.event.genE = 1;
			BfbGen_run_alg0(me);
			
			break;

		
		}
	}

	me->_trigger = false;

	//Ensure input events are cleared
	
}


