// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block VVI_LRI
#ifndef VVI_LRI_H_
#define VVI_LRI_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum VVI_LRI_states { STATE_VVI_LRI_Start, STATE_VVI_LRI_Resting, STATE_VVI_LRI_LRI_Timer_Expired, STATE_VVI_LRI_VSense_Detected };


union VVI_LRIInputEvents {
	struct {
		UDINT VSense;
		UDINT LRI_Timer_Timeout;
	} event;
	
};


union VVI_LRIOutputEvents {
	struct {
		UDINT LRI_Timer_Start;
		UDINT LRI_Timer_Stop;
		UDINT VPace;
	} event;
	
};


typedef struct {
    //input events
	union VVI_LRIInputEvents inputEvents;

    //output events
	union VVI_LRIOutputEvents outputEvents;

    //input vars
	
    //output vars
	INT LRI_Timeout_Value;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum VVI_LRI_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} VVI_LRI_t;

//all FBs get a preinit function
int VVI_LRI_preinit(VVI_LRI_t  *me);

//all FBs get an init function
int VVI_LRI_init(VVI_LRI_t  *me);

//all FBs get a run function
void VVI_LRI_run(VVI_LRI_t  *me);



#endif
