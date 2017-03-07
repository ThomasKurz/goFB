// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Composite Function Block for Pass10
#include "Pass10.h"

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


/* Pass10_preinit() is required to be called to 
 * initialise an instance of Pass10. 
 * It sets all I/O values to zero.
 */
int Pass10_preinit(Pass10_t _SPM *me) {
	//if there are input events, reset them
	me->inputEvents.event.CountChanged = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.OutCountChanged = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(Pass_preinit(&me->p1) != 0) {
		return 1;
	}
	if(Pass_preinit(&me->p2) != 0) {
		return 1;
	}
	if(Pass_preinit(&me->p3) != 0) {
		return 1;
	}
	if(Pass_preinit(&me->p4) != 0) {
		return 1;
	}
	if(Pass_preinit(&me->p5) != 0) {
		return 1;
	}
	if(Pass_preinit(&me->p9) != 0) {
		return 1;
	}
	if(Pass_preinit(&me->p6) != 0) {
		return 1;
	}
	if(Pass_preinit(&me->p10) != 0) {
		return 1;
	}
	if(Pass_preinit(&me->p7) != 0) {
		return 1;
	}
	if(Pass_preinit(&me->p8) != 0) {
		return 1;
	}
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	

	return 0;
}

/* Pass10_init() is required to be called to 
 * set up an instance of Pass10. 
 * It passes around configuration data.
 */
int Pass10_init(Pass10_t _SPM *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	me->p1.Count = me->Count;
	me->OutCount = me->p10.OutCount;
	me->p2.Count = me->p1.OutCount;
	me->p3.Count = me->p2.OutCount;
	me->p4.Count = me->p3.OutCount;
	me->p5.Count = me->p4.OutCount;
	me->p6.Count = me->p5.OutCount;
	me->p10.Count = me->p9.OutCount;
	me->p7.Count = me->p6.OutCount;
	me->p8.Count = me->p7.OutCount;
	me->p9.Count = me->p8.OutCount;
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(Pass_init(&me->p1) != 0) {
		return 1;
	}
	if(Pass_init(&me->p2) != 0) {
		return 1;
	}
	if(Pass_init(&me->p3) != 0) {
		return 1;
	}
	if(Pass_init(&me->p4) != 0) {
		return 1;
	}
	if(Pass_init(&me->p5) != 0) {
		return 1;
	}
	if(Pass_init(&me->p9) != 0) {
		return 1;
	}
	if(Pass_init(&me->p6) != 0) {
		return 1;
	}
	if(Pass_init(&me->p10) != 0) {
		return 1;
	}
	if(Pass_init(&me->p7) != 0) {
		return 1;
	}
	if(Pass_init(&me->p8) != 0) {
		return 1;
	}
	
	

	return 0;
}



/* Pass10_syncOutputEvents() synchronises the output events of an
 * instance of Pass10 as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void Pass10_syncOutputEvents(Pass10_t _SPM *me) {
	//first, for all cfb children, call this same function
	
	
	//then, for all connections that are connected to an output on the parent, run their run their copy
	
	me->outputEvents.event.OutCountChanged = me->p10.outputEvents.event.OutCountChanged; 
	
}

/* Pass10_syncInputEvents() synchronises the input events of an
 * instance of Pass10 as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void Pass10_syncInputEvents(Pass10_t _SPM *me) {
	//first, we explicitly synchronise the children
	
	me->p1.inputEvents.event.CountChanged = me->inputEvents.event.CountChanged; 
	
	me->p2.inputEvents.event.CountChanged = me->p1.outputEvents.event.OutCountChanged; 
	
	me->p3.inputEvents.event.CountChanged = me->p2.outputEvents.event.OutCountChanged; 
	
	me->p4.inputEvents.event.CountChanged = me->p3.outputEvents.event.OutCountChanged; 
	
	me->p5.inputEvents.event.CountChanged = me->p4.outputEvents.event.OutCountChanged; 
	
	me->p9.inputEvents.event.CountChanged = me->p8.outputEvents.event.OutCountChanged; 
	
	me->p6.inputEvents.event.CountChanged = me->p5.outputEvents.event.OutCountChanged; 
	
	me->p10.inputEvents.event.CountChanged = me->p9.outputEvents.event.OutCountChanged; 
	
	me->p7.inputEvents.event.CountChanged = me->p6.outputEvents.event.OutCountChanged; 
	
	me->p8.inputEvents.event.CountChanged = me->p7.outputEvents.event.OutCountChanged; 
	

	//then, call this same function on all cfb children
	
}

/* Pass10_syncOutputData() synchronises the output data connections of an
 * instance of Pass10 as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void Pass10_syncOutputData(Pass10_t _SPM *me) {
	//for all composite function block children, call this same function
	
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up) //TODO: arrays!?
	me->OutCount = me->p10.OutCount;
	
	
}

/* Pass10_syncInputData() synchronises the input data connections of an
 * instance of Pass10 as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void Pass10_syncInputData(Pass10_t _SPM *me) {
	//for all basic function block children, perform their synchronisations explicitly
	
	//sync for p1 (of type Pass) which is a BFB
	
	if(me->p1.inputEvents.event.CountChanged == 1) { 
		me->p1.Count = me->Count;
	} 
	
	//sync for p2 (of type Pass) which is a BFB
	
	if(me->p2.inputEvents.event.CountChanged == 1) { 
		me->p2.Count = me->p1.OutCount;
	} 
	
	//sync for p3 (of type Pass) which is a BFB
	
	if(me->p3.inputEvents.event.CountChanged == 1) { 
		me->p3.Count = me->p2.OutCount;
	} 
	
	//sync for p4 (of type Pass) which is a BFB
	
	if(me->p4.inputEvents.event.CountChanged == 1) { 
		me->p4.Count = me->p3.OutCount;
	} 
	
	//sync for p5 (of type Pass) which is a BFB
	
	if(me->p5.inputEvents.event.CountChanged == 1) { 
		me->p5.Count = me->p4.OutCount;
	} 
	
	//sync for p9 (of type Pass) which is a BFB
	
	if(me->p9.inputEvents.event.CountChanged == 1) { 
		me->p9.Count = me->p8.OutCount;
	} 
	
	//sync for p6 (of type Pass) which is a BFB
	
	if(me->p6.inputEvents.event.CountChanged == 1) { 
		me->p6.Count = me->p5.OutCount;
	} 
	
	//sync for p10 (of type Pass) which is a BFB
	
	if(me->p10.inputEvents.event.CountChanged == 1) { 
		me->p10.Count = me->p9.OutCount;
	} 
	
	//sync for p7 (of type Pass) which is a BFB
	
	if(me->p7.inputEvents.event.CountChanged == 1) { 
		me->p7.Count = me->p6.OutCount;
	} 
	
	//sync for p8 (of type Pass) which is a BFB
	
	if(me->p8.inputEvents.event.CountChanged == 1) { 
		me->p8.Count = me->p7.OutCount;
	} 
	
	
	//for all composite function block children, call this same function
	
	
}


/* Pass10_run() executes a single tick of an
 * instance of Pass10 according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void Pass10_run(Pass10_t _SPM *me) {
	Pass_run(&me->p1);
	Pass_run(&me->p2);
	Pass_run(&me->p3);
	Pass_run(&me->p4);
	Pass_run(&me->p5);
	Pass_run(&me->p9);
	Pass_run(&me->p6);
	Pass_run(&me->p10);
	Pass_run(&me->p7);
	Pass_run(&me->p8);
	
}

