// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Composite Function Block for InjectorController
#include "InjectorController.h"

//When running a composite block, note that you would call the functions in this order
//_init(); 
//do {
//_syncEvents();
//_syncData();
//_run();
//} loop;


/* InjectorController_preinit() is required to be called to 
 * initialise an instance of InjectorController. 
 * It sets all I/O values to zero.
 */
int InjectorController_preinit(struct InjectorController *me) {
	//if there are input events, reset them
	me->inputEvents.events[0] = 0;
	
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(InjectorMotorController_preinit(&me->Arm) != 0) {
		return 1;
	}
	if(InjectorPumpsController_preinit(&me->Pumps) != 0) {
		return 1;
	}
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	

	return 0;
}

/* InjectorController_init() is required to be called to 
 * set up an instance of InjectorController. 
 * It passes around configuration data.
 */
int InjectorController_init(struct InjectorController *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	me->Arm.EmergencyStop = me->EmergencyStop;
	me->Pumps.EmergencyStop = me->EmergencyStop;
	me->Pumps.CanisterPressure = me->CanisterPressure;
	me->Pumps.FillContentsAvailable = me->FillContentsAvailable;
	me->InjectorPosition = me->Arm.InjectorPosition;
	me->InjectorContentsValveOpen = me->Pumps.InjectorContentsValveOpen;
	me->InjectorVacuumRun = me->Pumps.InjectorVacuumRun;
	me->InjectorPressurePumpRun = me->Pumps.InjectorPressurePumpRun;
	me->FillContents = me->Pumps.FillContents;
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(InjectorMotorController_init(&me->Arm) != 0) {
		return 1;
	}
	if(InjectorPumpsController_init(&me->Pumps) != 0) {
		return 1;
	}
	
	

	return 0;
}



/* InjectorController_syncEvents() synchronises the events of an
 * instance of InjectorController as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void InjectorController_syncEvents(struct InjectorController *me) {
	//for all composite function block children, call this same function
	
	//for all basic function block children, perform their synchronisations explicitly
	//events are always copied
	
	me->Arm.inputEvents.event.InjectorArmFinishedMovement = me->inputEvents.event.InjectorArmFinishedMovement; 
	
	me->Arm.inputEvents.event.EmergencyStopChanged = me->inputEvents.event.EmergencyStopChanged; 
	
	me->Arm.inputEvents.event.ConveyorStoppedForInject = me->inputEvents.event.ConveyorStoppedForInject; 
	
	me->Arm.inputEvents.event.PumpFinished = me->Pumps.outputEvents.event.PumpFinished; 
	
	me->Pumps.inputEvents.event.StartPump = me->Arm.outputEvents.event.StartPump; 
	
	me->Pumps.inputEvents.event.EmergencyStopChanged = me->inputEvents.event.EmergencyStopChanged; 
	
	me->Pumps.inputEvents.event.CanisterPressureChanged = me->inputEvents.event.CanisterPressureChanged; 
	
	me->Pumps.inputEvents.event.FillContentsAvailableChanged = me->inputEvents.event.FillContentsAvailableChanged; 
	
	me->Pumps.inputEvents.event.VacuumTimerElapsed = me->inputEvents.event.VacuumTimerElapsed; 
	
	
}

/* InjectorController_syncData() synchronises the data connections of an
 * instance of InjectorController as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void InjectorController_syncData(struct InjectorController *me) {
	//for all composite function block children, call this same function
	
	//for all basic function block children, perform their synchronisations explicitly
	//Data is sometimes copied
	
	//sync for Arm (of type InjectorMotorController) which is a BFB
	
	if(me->Arm.inputEvents.event.EmergencyStopChanged == 1) { 
		me->Arm.EmergencyStop = me->EmergencyStop;
	} 
	
	//sync for Pumps (of type InjectorPumpsController) which is a BFB
	
	if(me->Pumps.inputEvents.event.EmergencyStopChanged == 1) { 
		me->Pumps.EmergencyStop = me->EmergencyStop;
	} 
	if(me->Pumps.inputEvents.event.CanisterPressureChanged == 1) { 
		me->Pumps.CanisterPressure = me->CanisterPressure;
	} 
	if(me->Pumps.inputEvents.event.FillContentsAvailableChanged == 1) { 
		me->Pumps.FillContentsAvailable = me->FillContentsAvailable;
	} 
	
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up)
	me->InjectorPosition = me->Arm.InjectorPosition;
	me->InjectorContentsValveOpen = me->Pumps.InjectorContentsValveOpen;
	me->InjectorVacuumRun = me->Pumps.InjectorVacuumRun;
	me->InjectorPressurePumpRun = me->Pumps.InjectorPressurePumpRun;
	me->FillContents = me->Pumps.FillContents;
	
	

}


/* InjectorController_run() executes a single tick of an
 * instance of InjectorController according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void InjectorController_run(struct InjectorController *me) {
	InjectorMotorController_run(&me->Arm);
	InjectorPumpsController_run(&me->Pumps);
	
}

