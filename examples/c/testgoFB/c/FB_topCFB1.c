// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Composite Function Block for topCFB1
#include "FB_topCFB1.h"

//When running a composite block, note that you would call the functions in this order (and this is very important)
//_preinit(); 
//_init();
//do {
//	_syncOutputEvents();
//	_syncInputEvents();
//	_syncOutputData();
//	_syncInputData();
//	_run();
//} loop;


/* topCFB1_preinit() is required to be called to 
 * initialise an instance of topCFB1. 
 * It sets all I/O values to zero.
 */
int topCFB1_preinit(topCFB1_t  *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(container_one_preinit(&me->cf1) != 0) {
		return 1;
	}
	if(container_one_preinit(&me->cf2) != 0) {
		return 1;
	}
	if(container_one_preinit(&me->cf3) != 0) {
		return 1;
	}
	if(container_one_preinit(&me->cf4) != 0) {
		return 1;
	}
	
	
	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	

	return 0;
}

/* topCFB1_init() is required to be called to 
 * set up an instance of topCFB1. 
 * It passes around configuration data.
 */
int topCFB1_init(topCFB1_t  *me) {
	//pass in any parameters on this level
	me->cf1.printf_id = 1;
	me->cf2.printf_id = 2;
	me->cf3.printf_id = 3;
	me->cf4.printf_id = 4;
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	
	//sync config for cf1 (of Type container_one) 
	
	
		me->cf1.DataIn = me->cf4.DataOut;
	
	//sync config for cf2 (of Type container_one) 
	
	
		me->cf2.DataIn = me->cf1.DataOut;
	
	//sync config for cf3 (of Type container_one) 
	
	
		me->cf3.DataIn = me->cf2.DataOut;
	
	//sync config for cf4 (of Type container_one) 
	
	
		me->cf4.DataIn = me->cf3.DataOut;
	
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(container_one_init(&me->cf1) != 0) {
		return 1;
	}
	if(container_one_init(&me->cf2) != 0) {
		return 1;
	}
	if(container_one_init(&me->cf3) != 0) {
		return 1;
	}
	if(container_one_init(&me->cf4) != 0) {
		return 1;
	}
	
	

	return 0;
}



/* topCFB1_syncOutputEvents() synchronises the output events of an
 * instance of topCFB1 as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void topCFB1_syncOutputEvents(topCFB1_t  *me) {
	//first, for all cfb children, call this same function
	
	container_one_syncOutputEvents(&me->cf1);//sync for cf1 (of type container_one) which is a CFB
	
	container_one_syncOutputEvents(&me->cf2);//sync for cf2 (of type container_one) which is a CFB
	
	container_one_syncOutputEvents(&me->cf3);//sync for cf3 (of type container_one) which is a CFB
	
	container_one_syncOutputEvents(&me->cf4);//sync for cf4 (of type container_one) which is a CFB
	
	
	//then, for all connections that are connected to an output on the parent, run their run their copy
	
}

/* topCFB1_syncInputEvents() synchronises the input events of an
 * instance of topCFB1 as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void topCFB1_syncInputEvents(topCFB1_t  *me) {
	//first, we explicitly synchronise the children
	
	me->cf1.inputEvents.event.DataInChanged = me->cf4.outputEvents.event.DataOutChanged; 
	
	me->cf2.inputEvents.event.DataInChanged = me->cf1.outputEvents.event.DataOutChanged; 
	
	me->cf3.inputEvents.event.DataInChanged = me->cf2.outputEvents.event.DataOutChanged; 
	
	me->cf4.inputEvents.event.DataInChanged = me->cf3.outputEvents.event.DataOutChanged; 
	

	//then, call this same function on all cfb children
	
	container_one_syncInputEvents(&me->cf1);//sync for cf1 (of type container_one) which is a CFB
	
	container_one_syncInputEvents(&me->cf2);//sync for cf2 (of type container_one) which is a CFB
	
	container_one_syncInputEvents(&me->cf3);//sync for cf3 (of type container_one) which is a CFB
	
	container_one_syncInputEvents(&me->cf4);//sync for cf4 (of type container_one) which is a CFB
	
}

/* topCFB1_syncOutputData() synchronises the output data connections of an
 * instance of topCFB1 as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void topCFB1_syncOutputData(topCFB1_t  *me) {
	//for all composite function block children, call this same function
	//sync for cf1 (of type container_one) which is a CFB
	container_one_syncOutputData(&me->cf1);//sync for cf2 (of type container_one) which is a CFB
	container_one_syncOutputData(&me->cf2);//sync for cf3 (of type container_one) which is a CFB
	container_one_syncOutputData(&me->cf3);//sync for cf4 (of type container_one) which is a CFB
	container_one_syncOutputData(&me->cf4);
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up) //TODO: arrays!?
	
	
}

/* topCFB1_syncInputData() synchronises the input data connections of an
 * instance of topCFB1 as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void topCFB1_syncInputData(topCFB1_t  *me) {
	//for all basic function block children, perform their synchronisations explicitly
	//sync for cf1 (of Type container_one) which is a CFB
	
	
		me->cf1.DataIn = me->cf4.DataOut;
	
	//sync for cf2 (of Type container_one) which is a CFB
	
	
		me->cf2.DataIn = me->cf1.DataOut;
	
	//sync for cf3 (of Type container_one) which is a CFB
	
	
		me->cf3.DataIn = me->cf2.DataOut;
	
	//sync for cf4 (of Type container_one) which is a CFB
	
	
		me->cf4.DataIn = me->cf3.DataOut;
	
	
	
	//for all composite function block children, call this same function
	//sync for cf1 (of type container_one) which is a CFB
	container_one_syncInputData(&me->cf1);//sync for cf2 (of type container_one) which is a CFB
	container_one_syncInputData(&me->cf2);//sync for cf3 (of type container_one) which is a CFB
	container_one_syncInputData(&me->cf3);//sync for cf4 (of type container_one) which is a CFB
	container_one_syncInputData(&me->cf4);
	
}


/* topCFB1_run() executes a single tick of an
 * instance of topCFB1 according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void topCFB1_run(topCFB1_t  *me) {
	container_one_run(&me->cf1);
	container_one_run(&me->cf2);
	container_one_run(&me->cf3);
	container_one_run(&me->cf4);
	
}
