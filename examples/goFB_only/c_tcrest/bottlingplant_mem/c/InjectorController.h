// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block InjectorController
#ifndef INJECTORCONTROLLER_H_
#define INJECTORCONTROLLER_H_

#include "fbtypes.h"

//This is a CFB, so we need the #includes for the child blocks embedded here
#include "InjectorMotorController.h"
#include "InjectorPumpsController.h"


union InjectorControllerInputEvents {
	struct {
		UDINT InjectorArmFinishedMovement;
		UDINT EmergencyStopChanged;
		UDINT CanisterPressureChanged;
		UDINT FillContentsAvailableChanged;
		UDINT ConveyorStoppedForInject;
		UDINT VacuumTimerElapsed;
	} event;
	
};


union InjectorControllerOutputEvents {
	struct {
		UDINT InjectDone;
		UDINT InjectorPositionChanged;
		UDINT InjectorControlsChanged;
		UDINT RejectCanister;
		UDINT FillContentsChanged;
		UDINT StartVacuumTimer;
		UDINT InjectRunning;
	} event;
	
};


typedef struct {
    //input events
	union InjectorControllerInputEvents inputEvents;

    //output events
	union InjectorControllerOutputEvents outputEvents;

    //input vars
	BOOL EmergencyStop;
    BYTE CanisterPressure;
    BYTE FillContentsAvailable;
    
    //output vars
	BYTE InjectorPosition;
    BOOL InjectorContentsValveOpen;
    BOOL InjectorVacuumRun;
    BOOL InjectorPressurePumpRun;
    BOOL FillContents;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	InjectorMotorController_t Arm;
	InjectorPumpsController_t Pumps;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} InjectorController_t;

//all FBs get a preinit function
int InjectorController_preinit(InjectorController_t  *me);

//all FBs get an init function
int InjectorController_init(InjectorController_t  *me);

//all FBs get a run function
void InjectorController_run(InjectorController_t  *me);

//composite/resource/device FBs get sync functions
void InjectorController_syncOutputEvents(InjectorController_t  *me);
void InjectorController_syncInputEvents(InjectorController_t  *me);

void InjectorController_syncOutputData(InjectorController_t  *me);
void InjectorController_syncInputData(InjectorController_t  *me);



#endif
