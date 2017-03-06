// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Composite Function Block for FakePacemakerTop
#include "FakePacemakerTop.h"

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


/* FakePacemakerTop_preinit() is required to be called to 
 * initialise an instance of FakePacemakerTop. 
 * It sets all I/O values to zero.
 */
int FakePacemakerTop_preinit(FakePacemakerTop_t _SPM *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(VVI_Pacemaker_preinit(&me->pmaker) != 0) {
		return 1;
	}
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	

	return 0;
}

/* FakePacemakerTop_init() is required to be called to 
 * set up an instance of FakePacemakerTop. 
 * It passes around configuration data.
 */
int FakePacemakerTop_init(FakePacemakerTop_t _SPM *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(VVI_Pacemaker_init(&me->pmaker) != 0) {
		return 1;
	}
	
	

	return 0;
}



/* FakePacemakerTop_syncOutputEvents() synchronises the output events of an
 * instance of FakePacemakerTop as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void FakePacemakerTop_syncOutputEvents(FakePacemakerTop_t _SPM *me) {
	//first, for all cfb children, call this same function
	
	VVI_Pacemaker_syncOutputEvents(&me->pmaker);//sync for pmaker (of type VVI_Pacemaker) which is a CFB
	
	
	//then, for all connections that are connected to an output on the parent, run their run their copy
	
}

/* FakePacemakerTop_syncInputEvents() synchronises the input events of an
 * instance of FakePacemakerTop as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void FakePacemakerTop_syncInputEvents(FakePacemakerTop_t _SPM *me) {
	//first, we explicitly synchronise the children
	
	me->pmaker.inputEvents.event.VPulse = me->pmaker.outputEvents.event.VPace; 
	
	me->pmaker.inputEvents.event.VRP_Timer_Timeout = me->pmaker.outputEvents.event.VRP_Start_Timer; 
	
	me->pmaker.inputEvents.event.LRI_Timer_Timeout = me->pmaker.outputEvents.event.LRI_Timer_Start; 
	

	//then, call this same function on all cfb children
	
	VVI_Pacemaker_syncInputEvents(&me->pmaker);//sync for pmaker (of type VVI_Pacemaker) which is a CFB
	
}

/* FakePacemakerTop_syncOutputData() synchronises the output data connections of an
 * instance of FakePacemakerTop as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void FakePacemakerTop_syncOutputData(FakePacemakerTop_t _SPM *me) {
	//for all composite function block children, call this same function
	//sync for pmaker (of type VVI_Pacemaker) which is a CFB
	VVI_Pacemaker_syncOutputData(&me->pmaker);
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up) //TODO: arrays!?
	
	
}

/* FakePacemakerTop_syncInputData() synchronises the input data connections of an
 * instance of FakePacemakerTop as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void FakePacemakerTop_syncInputData(FakePacemakerTop_t _SPM *me) {
	//for all basic function block children, perform their synchronisations explicitly
	//sync for pmaker (of Type VVI_Pacemaker) which is a CFB
	
	
	//for all composite function block children, call this same function
	//sync for pmaker (of type VVI_Pacemaker) which is a CFB
	VVI_Pacemaker_syncInputData(&me->pmaker);
	
}


/* FakePacemakerTop_run() executes a single tick of an
 * instance of FakePacemakerTop according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void FakePacemakerTop_run(FakePacemakerTop_t _SPM *me) {
	VVI_Pacemaker_run(&me->pmaker);
	
}

