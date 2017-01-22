// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block RejectArmController
#ifndef REJECTARMCONTROLLER_H_
#define REJECTARMCONTROLLER_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum RejectArmController_states { STATE_RejectArmController_Clear, STATE_RejectArmController_AwaitCanister, STATE_RejectArmController_GoReject };


union RejectArmControllerInputEvents {
	struct {
		UDINT RejectCanister : 1;
		UDINT LasersChanged : 1;
	} event;
	UDINT events[1];
};


union RejectArmControllerOutputEvents {
	struct {
		UDINT GoRejectArm : 1;
	} event;
	UDINT events[1];
};


typedef struct {
    //input events
	union RejectArmControllerInputEvents inputEvents;

    //output events
	union RejectArmControllerOutputEvents outputEvents;

    //input vars
	BOOL RejectSiteLaser;
    
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum RejectArmController_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
}  RejectArmController_t;

//all FBs get a preinit function
int RejectArmController_preinit(RejectArmController_t *me);

//all FBs get an init function
int RejectArmController_init(RejectArmController_t *me);

//all FBs get a run function
void RejectArmController_run(RejectArmController_t *me);




#endif
