// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block PrintInt
#ifndef PRINTINT_H_
#define PRINTINT_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum PrintInt_states { STATE_PrintInt_Start, STATE_PrintInt_Await_Data };


union PrintIntInputEvents {
	struct {
		UDINT DataPresent : 1;
	} event;
	UDINT events[1];
};


//this block had no output events


typedef struct {
    //input events
	union PrintIntInputEvents inputEvents;

    //output events
	

    //input vars
	INT Data;
    
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum PrintInt_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} _SPM PrintInt_t;

//all FBs get a preinit function
int PrintInt_preinit(PrintInt_t *me);

//all FBs get an init function
int PrintInt_init(PrintInt_t *me);

//all FBs get a run function
void PrintInt_run(PrintInt_t *me);


//basic FBs have a number of algorithm functions

void PrintInt_DoPrintInt(PrintInt_t *me);


#endif
