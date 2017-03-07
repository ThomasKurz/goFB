// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block _Core102
#ifndef _CORE102_H_
#define _CORE102_H_

#include "fbtypes.h"

//This is a CFB, so we need the #includes for the child blocks embedded here
#include "Gen.h"
#include "Print.h"
#include "Pass50.h"
#include "Pass50.h"


//this block had no input events


//this block had no output events


typedef struct {
    //input events
	

    //output events
	

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	Gen_t gen;
	Print_t print;
	Pass50_t p50_1;
	Pass50_t p50_2;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} _Core102_t;

//all FBs get a preinit function
int _Core102_preinit(_Core102_t _SPM *me);

//all FBs get an init function
int _Core102_init(_Core102_t _SPM *me);

//all FBs get a run function
void _Core102_run(_Core102_t _SPM *me);

//composite/resource/device FBs get sync functions
void _Core102_syncOutputEvents(_Core102_t _SPM *me);
void _Core102_syncInputEvents(_Core102_t _SPM *me);

void _Core102_syncOutputData(_Core102_t _SPM *me);
void _Core102_syncInputData(_Core102_t _SPM *me);



#endif
