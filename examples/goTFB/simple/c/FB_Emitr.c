// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for Emitr
#include "FB_Emitr.h"


/* Emitr_preinit() is required to be called to 
 * initialise an instance of Emitr. 
 * It sets all I/O values to zero.
 */
int Emitr_preinit(Emitr_t  *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	me->outputEvents.event.e = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	//Code provided in SIFB
	

	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	

	return 0;
}

/* Emitr_init() is required to be called to 
 * set up an instance of Emitr. 
 * It passes around configuration data.
 */
int Emitr_init(Emitr_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	
	

	//Code provided in SIFB
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



/* Emitr_run() executes a single tick of an
 * instance of Emitr. As it is a SIFB, the execution code is provided
 */
void Emitr_run(Emitr_t  *me) {
	//Code provided in SIFB
	me->outputEvents.event.e = 1;
}

