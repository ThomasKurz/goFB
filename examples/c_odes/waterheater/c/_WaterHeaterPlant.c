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
	if(WaterHeaterPlantODE_preinit(&me->waterHeaterPlantODE1) != 0) {
		return 1;
	}
	if(interResourceTxLReal_preinit(&me->t_tx1) != 0) {
		return 1;
	}
	if(interResourceRxBool_preinit(&me->heat_rx1) != 0) {
		return 1;
	}
	if(StartGen_preinit(&me->StartGen) != 0) {
		return 1;
	}
	if(WaterHeaterPlantODE_preinit(&me->waterHeaterPlandODE2) != 0) {
		return 1;
	}
	if(interResourceTxLReal_preinit(&me->t_tx2) != 0) {
		return 1;
	}
	if(interResourceRxBool_preinit(&me->heat_rx2) != 0) {
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
	me->waterHeaterPlantODE1.K = 0.075;
	me->waterHeaterPlantODE1.H = 150;
	me->t_tx1.Channel = 2;
	me->heat_rx1.Channel = 0;
	me->StartGen.SetDeltaTime = 0.5;
	me->waterHeaterPlandODE2.K = 0.075;
	me->waterHeaterPlandODE2.H = 150;
	me->t_tx2.Channel = 3;
	me->heat_rx2.Channel = 1;
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	me->t_tx1.Data = me->waterHeaterPlantODE1.Y;
	me->waterHeaterPlantODE1.Heat = me->heat_rx1.Data;
	me->waterHeaterPlantODE1.DeltaTime = me->StartGen.DeltaTime;
	me->waterHeaterPlandODE2.DeltaTime = me->StartGen.DeltaTime;
	me->t_tx2.Data = me->waterHeaterPlandODE2.Y;
	me->waterHeaterPlandODE2.Heat = me->heat_rx2.Data;
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(WaterHeaterPlantODE_init(&me->waterHeaterPlantODE1) != 0) {
		return 1;
	}
	if(interResourceTxLReal_init(&me->t_tx1) != 0) {
		return 1;
	}
	if(interResourceRxBool_init(&me->heat_rx1) != 0) {
		return 1;
	}
	if(StartGen_init(&me->StartGen) != 0) {
		return 1;
	}
	if(WaterHeaterPlantODE_init(&me->waterHeaterPlandODE2) != 0) {
		return 1;
	}
	if(interResourceTxLReal_init(&me->t_tx2) != 0) {
		return 1;
	}
	if(interResourceRxBool_init(&me->heat_rx2) != 0) {
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
	
	me->waterHeaterPlantODE1.inputEvents.event.HeatChange = me->heat_rx1.outputEvents.event.Rx; 
	
	me->waterHeaterPlantODE1.inputEvents.event.Start = 0; 
	
	me->t_tx1.inputEvents.event.Tx = me->waterHeaterPlantODE1.outputEvents.event.Ychange; 
	
	me->waterHeaterPlandODE2.inputEvents.event.HeatChange = me->heat_rx2.outputEvents.event.Rx; 
	
	me->waterHeaterPlandODE2.inputEvents.event.Start = 0; 
	
	me->t_tx2.inputEvents.event.Tx = me->waterHeaterPlandODE2.outputEvents.event.Ychange; 
	

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
	
	//sync for waterHeaterPlantODE1 (of type WaterHeaterPlantODE) which is a BFB
	
	if(me->waterHeaterPlantODE1.inputEvents.event.HeatChange == 1) { 
		me->waterHeaterPlantODE1.Heat = me->heat_rx1.Data;
	} 
	if(me->waterHeaterPlantODE1.inputEvents.event.Start == 1) { 
		me->waterHeaterPlantODE1.DeltaTime = me->StartGen.DeltaTime;
	} 
	
	//sync for t_tx1 (of type interResourceTxLReal) which is a BFB
	
	if(me->t_tx1.inputEvents.event.Tx == 1) { 
		me->t_tx1.Data = me->waterHeaterPlantODE1.Y;
	} 
	
	//sync for heat_rx1 (of type interResourceRxBool) which is a BFB
	
	
	//sync for StartGen (of type StartGen) which is a BFB
	
	
	//sync for waterHeaterPlandODE2 (of type WaterHeaterPlantODE) which is a BFB
	
	if(me->waterHeaterPlandODE2.inputEvents.event.HeatChange == 1) { 
		me->waterHeaterPlandODE2.Heat = me->heat_rx2.Data;
	} 
	if(me->waterHeaterPlandODE2.inputEvents.event.Start == 1) { 
		me->waterHeaterPlandODE2.DeltaTime = me->StartGen.DeltaTime;
	} 
	
	//sync for t_tx2 (of type interResourceTxLReal) which is a BFB
	
	if(me->t_tx2.inputEvents.event.Tx == 1) { 
		me->t_tx2.Data = me->waterHeaterPlandODE2.Y;
	} 
	
	//sync for heat_rx2 (of type interResourceRxBool) which is a BFB
	
	
	
	//for all composite function block children, call this same function
	
	
}


/* _WaterHeaterPlant_run() executes a single tick of an
 * instance of _WaterHeaterPlant according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void _WaterHeaterPlant_run(_WaterHeaterPlant_t  *me) {
	WaterHeaterPlantODE_run(&me->waterHeaterPlantODE1);
	interResourceTxLReal_run(&me->t_tx1);
	interResourceRxBool_run(&me->heat_rx1);
	StartGen_run(&me->StartGen);
	WaterHeaterPlantODE_run(&me->waterHeaterPlandODE2);
	interResourceTxLReal_run(&me->t_tx2);
	interResourceRxBool_run(&me->heat_rx2);
	
}

