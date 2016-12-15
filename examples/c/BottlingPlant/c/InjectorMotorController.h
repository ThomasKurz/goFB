// This file has been automatically generated by go-iec61499 and should not be edited by hand
// Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499

// This file represents the interface of Function Block InjectorMotorController
#include "fbtypes.h"



union InjectorMotorControllerInputEvents {
	struct {
		UDINT InjectorArmFinishedMovement : 1;
		UDINT EmergencyStopChanged : 1;
		UDINT ConveyorStoppedForInject : 1;
		UDINT PumpFinished : 1;
	} event;
	UDINT events[1];
};

union InjectorMotorControllerOutputEvents {
	struct {
		UDINT StartPump : 1;
		UDINT InjectDone : 1;
		UDINT InjectorPositionChanged : 1;
		UDINT InjectRunning : 1;
	} event;
	UDINT events[1];
};

struct InjectorMotorController {
    //input events
    union InjectorMotorControllerInputEvents inputEvents;

    //output events
    union InjectorMotorControllerOutputEvents outputEvents;

    //input vars
	BOOL EmergencyStop;
    
    //output vars
	BYTE InjectorPosition;
    
    //internal vars
	//child FBs 
	
};

//all FBs get an init function
void InjectorMotorController_init(struct InjectorMotorController *me);

//all FBs get a run function
void InjectorMotorController_run(struct InjectorMotorController *me);


//basic FBs have a number of algorithm functions

void InjectorMotorController_SetArmDownPosition(struct InjectorMotorController *me);

void InjectorMotorController_SetArmUpPosition(struct InjectorMotorController *me);

void InjectorMotorController_Algorithm1(struct InjectorMotorController *me);

