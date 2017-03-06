// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block VVI_Pacemaker
#ifndef VVI_PACEMAKER_H_
#define VVI_PACEMAKER_H_

#include "fbtypes.h"

//This is a CFB, so we need the #includes for the child blocks embedded here
#include "VVI_LRI.h"
#include "VVI_VRP.h"


union VVI_PacemakerInputEvents {
	struct {
		UDINT VPulse;
		UDINT VRP_Timer_Timeout;
		UDINT LRI_Timer_Timeout;
	} event;
	
};


union VVI_PacemakerOutputEvents {
	struct {
		UDINT VPace;
		UDINT VRefractory;
		UDINT VRP_Start_Timer;
		UDINT LRI_Timer_Start;
		UDINT LRI_Timer_Stop;
	} event;
	
};


typedef struct {
    //input events
	union VVI_PacemakerInputEvents inputEvents;

    //output events
	union VVI_PacemakerOutputEvents outputEvents;

    //input vars
	
    //output vars
	INT VRP_Timeout_Value;
    INT LRI_Timeout_Value;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	VVI_LRI_t VVI_LRI;
	VVI_VRP_t VVI_VRP;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} VVI_Pacemaker_t;

//all FBs get a preinit function
int VVI_Pacemaker_preinit(VVI_Pacemaker_t _SPM *me);

//all FBs get an init function
int VVI_Pacemaker_init(VVI_Pacemaker_t _SPM *me);

//all FBs get a run function
void VVI_Pacemaker_run(VVI_Pacemaker_t _SPM *me);

//composite/resource/device FBs get sync functions
void VVI_Pacemaker_syncOutputEvents(VVI_Pacemaker_t _SPM *me);
void VVI_Pacemaker_syncInputEvents(VVI_Pacemaker_t _SPM *me);

void VVI_Pacemaker_syncOutputData(VVI_Pacemaker_t _SPM *me);
void VVI_Pacemaker_syncInputData(VVI_Pacemaker_t _SPM *me);



#endif
