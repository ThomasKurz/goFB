// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block SawmillModule
#ifndef SAWMILLMODULE_H_
#define SAWMILLMODULE_H_

#include "fbtypes.h"

//This is a CFB, so we need the #includes for the child blocks embedded here
#include "SawmillSwitch.h"
#include "SawMotor.h"
#include "SawdustScale.h"
#include "SawmillLaser.h"
#include "SawmillControl.h"


//this block had no input events


union SawmillModuleOutputEvents {
	struct {
		UDINT MessageChange : 1;
	} event;
	UDINT events[1];
};


typedef struct {
    //input events
	

    //output events
	union SawmillModuleOutputEvents outputEvents;

    //input vars
	
    //output vars
	INT Message;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	struct SawmillSwitch runswitch;
	struct SawMotor saw;
	struct SawdustScale scale;
	struct SawmillLaser laser;
	struct SawmillControl control;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} _SPM SawmillModule_t;

//all FBs get a preinit function
int SawmillModule_preinit(SawmillModule *me);

//all FBs get an init function
int SawmillModule_init(SawmillModule *me);

//all FBs get a run function
void SawmillModule_run(SawmillModule *me);

//composite/resource/device FBs get sync functions
void SawmillModule_syncEvents(SawmillModule *me);
void SawmillModule_syncData(SawmillModule *me);

#endif
