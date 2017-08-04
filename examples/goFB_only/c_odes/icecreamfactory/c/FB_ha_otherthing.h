// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block ha_otherthing
#ifndef HA_OTHERTHING_H_
#define HA_OTHERTHING_H_

#include "fbtypes.h"
#include "util.h"


#include "cvode/cvode.h"
#include "nvector/nvector_serial.h"
#include "cvode/cvode_dense.h"
#include "sundials/sundials_dense.h"
#include "sundials/sundials_types.h"


//This is a BFB, so we need an enum type for the state machine
enum ha_otherthing_states { STATE_ha_otherthing_Start, STATE_ha_otherthing_StartEntryState, STATE_ha_otherthing_State1, STATE_ha_otherthing_State2E0, STATE_ha_otherthing_State2E1, STATE_ha_otherthing_State2, STATE_ha_otherthing_State3E0, STATE_ha_otherthing_State3E1, STATE_ha_otherthing_State3, STATE_ha_otherthing_State1E1 };


union ha_otherthingInputEvents {
	struct {
		UDINT S2;
		UDINT S3;
	} event;
	
};


union ha_otherthingOutputEvents {
	struct {
		UDINT update;
	} event;
	
};


typedef struct {
    //input events
	union ha_otherthingInputEvents inputEvents;

    //output events
	union ha_otherthingOutputEvents outputEvents;

    //input vars
	LREAL DeltaTime;
    
    //output vars
	LREAL y;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum ha_otherthing_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	//this block uses cvode
	void *cvode_mem;
	N_Vector ode_solution;
	realtype T0;
	realtype Tnext;
	realtype Tcurr;
	int solveInProgress;
	

	
} ha_otherthing_t;

//all FBs get a preinit function
int ha_otherthing_preinit(ha_otherthing_t  *me);

//all FBs get an init function
int ha_otherthing_init(ha_otherthing_t  *me);

//all FBs get a run function
void ha_otherthing_run(ha_otherthing_t  *me);



#endif