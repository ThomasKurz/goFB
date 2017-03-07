// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block InjectorMotorController
#ifndef INJECTORMOTORCONTROLLER_H_
#define INJECTORMOTORCONTROLLER_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum InjectorMotorController_states { STATE_InjectorMotorController_MoveArmUp, STATE_InjectorMotorController_Await_Bottle, STATE_InjectorMotorController_MoveArmDown, STATE_InjectorMotorController_Await_Pumping };


union InjectorMotorControllerInputEvents {
	struct {
		UDINT InjectorArmFinishedMovement;
		UDINT EmergencyStopChanged;
		UDINT ConveyorStoppedForInject;
		UDINT PumpFinished;
	} event;
	
};


union InjectorMotorControllerOutputEvents {
	struct {
		UDINT StartPump;
		UDINT InjectDone;
		UDINT InjectorPositionChanged;
		UDINT InjectRunning;
	} event;
	
};


typedef struct {
    //input events
	union InjectorMotorControllerInputEvents inputEvents;

    //output events
	union InjectorMotorControllerOutputEvents outputEvents;

    //input vars
	BOOL EmergencyStop;
    
    //output vars
	BYTE InjectorPosition;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum InjectorMotorController_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} InjectorMotorController_t;

//all FBs get a preinit function
int InjectorMotorController_preinit(InjectorMotorController_t  *me);

//all FBs get an init function
int InjectorMotorController_init(InjectorMotorController_t  *me);

//all FBs get a run function
void InjectorMotorController_run(InjectorMotorController_t  *me);



#endif
