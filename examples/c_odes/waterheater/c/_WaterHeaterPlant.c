// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Composite Function Block for _WaterHeaterPlant
#include "_WaterHeaterPlant.h"

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


/* _WaterHeaterPlant_preinit() is required to be called to 
 * initialise an instance of _WaterHeaterPlant. 
 * It sets all I/O values to zero.
 */
int _WaterHeaterPlant_preinit(_WaterHeaterPlant_t  *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(WaterHeaterPlantODE_preinit(&me->waterHeaterPlantODE) != 0) {
		return 1;
	}
	if(interResourceTxLReal_preinit(&me->t_tx) != 0) {
		return 1;
	}
	if(interResourceRxBool_preinit(&me->heat_rx) != 0) {
		return 1;
	}
	if(TickGen_preinit(&me->tickgen) != 0) {
		return 1;
	}
	
	
	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	
	
	return 0;
}

/* _WaterHeaterPlant_init() is required to be called to 
 * set up an instance of _WaterHeaterPlant. 
 * It passes around configuration data.
 */
int _WaterHeaterPlant_init(_WaterHeaterPlant_t  *me) {
	//pass in any parameters on this level
	me->waterHeaterPlantODE.K = 0.075;
	me->waterHeaterPlantODE.H = 150;
	me->t_tx.Channel = 1;
	me->heat_rx.Channel = 0;
	me->tickgen.SetDeltaTime = 2.5;
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	me->t_tx.Data = me->waterHeaterPlantODE.Y;
	me->waterHeaterPlantODE.Heat = me->heat_rx.Data;
	me->waterHeaterPlantODE.DeltaTime = me->tickgen.DeltaTime;
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(WaterHeaterPlantODE_init(&me->waterHeaterPlantODE) != 0) {
		return 1;
	}
	if(interResourceTxLReal_init(&me->t_tx) != 0) {
		return 1;
	}
	if(interResourceRxBool_init(&me->heat_rx) != 0) {
		return 1;
	}
	if(TickGen_init(&me->tickgen) != 0) {
		return 1;
	}
	
	

	return 0;
}



/* _WaterHeaterPlant_syncOutputEvents() synchronises the output events of an
 * instance of _WaterHeaterPlant as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _WaterHeaterPlant_syncOutputEvents(_WaterHeaterPlant_t  *me) {
	//first, for all cfb children, call this same function
	
	
	//then, for all connections that are connected to an output on the parent, run their run their copy
	
}

/* _WaterHeaterPlant_syncInputEvents() synchronises the input events of an
 * instance of _WaterHeaterPlant as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _WaterHeaterPlant_syncInputEvents(_WaterHeaterPlant_t  *me) {
	//first, we explicitly synchronise the children
	
	me->waterHeaterPlantODE.inputEvents.event.HeatChange = me->heat_rx.outputEvents.event.Rx; 
	
	me->waterHeaterPlantODE.inputEvents.event.Tick = me->tickgen.outputEvents.event.Tick; 
	
	me->t_tx.inputEvents.event.Tx = me->waterHeaterPlantODE.outputEvents.event.Ychange; 
	

	//then, call this same function on all cfb children
	
}

/* _WaterHeaterPlant_syncOutputData() synchronises the output data connections of an
 * instance of _WaterHeaterPlant as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _WaterHeaterPlant_syncOutputData(_WaterHeaterPlant_t  *me) {
	//for all composite function block children, call this same function
	
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up) //TODO: arrays!?
	
	
}

/* _WaterHeaterPlant_syncInputData() synchronises the input data connections of an
 * instance of _WaterHeaterPlant as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _WaterHeaterPlant_syncInputData(_WaterHeaterPlant_t  *me) {
	//for all basic function block children, perform their synchronisations explicitly
	
	//sync for waterHeaterPlantODE (of type WaterHeaterPlantODE) which is a BFB
	
	if(me->waterHeaterPlantODE.inputEvents.event.HeatChange == 1) { 
		me->waterHeaterPlantODE.Heat = me->heat_rx.Data;
	} 
	if(me->waterHeaterPlantODE.inputEvents.event.Tick == 1) { 
		me->waterHeaterPlantODE.DeltaTime = me->tickgen.DeltaTime;
	} 
	
	//sync for t_tx (of type interResourceTxLReal) which is a BFB
	
	if(me->t_tx.inputEvents.event.Tx == 1) { 
		me->t_tx.Data = me->waterHeaterPlantODE.Y;
	} 
	
	//sync for heat_rx (of type interResourceRxBool) which is a BFB
	
	
	//sync for tickgen (of type TickGen) which is a BFB
	
	
	
	//for all composite function block children, call this same function
	
	
}


/* _WaterHeaterPlant_run() executes a single tick of an
 * instance of _WaterHeaterPlant according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void _WaterHeaterPlant_run(_WaterHeaterPlant_t  *me) {
	WaterHeaterPlantODE_run(&me->waterHeaterPlantODE);
	interResourceTxLReal_run(&me->t_tx);
	interResourceRxBool_run(&me->heat_rx);
	TickGen_run(&me->tickgen);
	
}

