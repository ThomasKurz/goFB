// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block Controller
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "fbtypes.h"



//This is a BFB, so we need an enum type for the state machine
enum Controller_states { STATE_Controller_Start, STATE_Controller_h1, STATE_Controller_h2 };


union ControllerInputEvents {
	struct {
		UDINT TChange1;
		UDINT TChange2;
	} event;
	
};


union ControllerOutputEvents {
	struct {
		UDINT HeatChange;
	} event;
	
};


typedef struct {
    //input events
	union ControllerInputEvents inputEvents;

    //output events
	union ControllerOutputEvents outputEvents;

    //input vars
	LREAL T1;
    LREAL T2;
    
    //output vars
	BOOL Heat1;
    BOOL Heat2;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum Controller_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	

	
} Controller_t;

//all FBs get a preinit function
int Controller_preinit(Controller_t  *me);

//all FBs get an init function
int Controller_init(Controller_t  *me);

//all FBs get a run function
void Controller_run(Controller_t  *me);



#endif
