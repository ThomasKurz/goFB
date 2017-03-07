// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Device Function Block for _TCREST
#include "_TCREST.h"

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



/* _TCREST_preinit() is required to be called to 
 * initialise an instance of _TCREST. 
 * It sets all I/O values to zero.
 */
int _TCREST_preinit(_TCREST_t _SPM *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	if(_Core102_preinit(&me->c1) != 0) {
		return 1;
	}
	if(_Core102_preinit(&me->c2) != 0) {
		return 1;
	}
	if(_Core102_preinit(&me->c3) != 0) {
		return 1;
	}
	if(_Core102_preinit(&me->c4) != 0) {
		return 1;
	}
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	

	return 0;
}

/* _TCREST_init() is required to be called to 
 * set up an instance of _TCREST. 
 * It passes around configuration data.
 */
int _TCREST_init(_TCREST_t _SPM *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	if(_Core102_init(&me->c1) != 0) {
		return 1;
	}
	if(_Core102_init(&me->c2) != 0) {
		return 1;
	}
	if(_Core102_init(&me->c3) != 0) {
		return 1;
	}
	if(_Core102_init(&me->c4) != 0) {
		return 1;
	}
	

	return 0;
}



/* _TCREST_sync[Output/Input]Events() synchronises the events of an
 * instance of _TCREST as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _TCREST_syncOutputEvents(_TCREST_t _SPM *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for c1 (of type _Core102) which is a Resource
	_Core102_syncOutputEvents(&me->c1);//sync for c2 (of type _Core102) which is a Resource
	_Core102_syncOutputEvents(&me->c2);//sync for c3 (of type _Core102) which is a Resource
	_Core102_syncOutputEvents(&me->c3);//sync for c4 (of type _Core102) which is a Resource
	_Core102_syncOutputEvents(&me->c4);
	
}
void _TCREST_syncInputEvents(_TCREST_t _SPM *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for c1 (of type _Core102) which is a Resource
	_Core102_syncInputEvents(&me->c1);//sync for c2 (of type _Core102) which is a Resource
	_Core102_syncInputEvents(&me->c2);//sync for c3 (of type _Core102) which is a Resource
	_Core102_syncInputEvents(&me->c3);//sync for c4 (of type _Core102) which is a Resource
	_Core102_syncInputEvents(&me->c4);
	
}

/* _TCREST_sync[Output/Input]Data() synchronises the data connections of an
 * instance of _TCREST as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _TCREST_syncOutputData(_TCREST_t _SPM *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for c1 (of type _Core102) which is a Resource
	_Core102_syncOutputData(&me->c1);//sync for c2 (of type _Core102) which is a Resource
	_Core102_syncOutputData(&me->c2);//sync for c3 (of type _Core102) which is a Resource
	_Core102_syncOutputData(&me->c3);//sync for c4 (of type _Core102) which is a Resource
	_Core102_syncOutputData(&me->c4);

}
void _TCREST_syncInputData(_TCREST_t _SPM *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for c1 (of type _Core102) which is a Resource
	_Core102_syncInputData(&me->c1);//sync for c2 (of type _Core102) which is a Resource
	_Core102_syncInputData(&me->c2);//sync for c3 (of type _Core102) which is a Resource
	_Core102_syncInputData(&me->c3);//sync for c4 (of type _Core102) which is a Resource
	_Core102_syncInputData(&me->c4);

}


/* _TCREST_run() executes a single tick of an
 * instance of _TCREST according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void _TCREST_run(_TCREST_t _SPM *me) {
	_Core102_run(&me->c1);
	_Core102_run(&me->c2);
	_Core102_run(&me->c3);
	_Core102_run(&me->c4);
	
}

