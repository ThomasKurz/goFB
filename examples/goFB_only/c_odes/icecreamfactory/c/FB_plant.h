// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block plant
#ifndef PLANT_H_
#define PLANT_H_

#include "fbtypes.h"
#include "util.h"



//This is a CFB, so we need the #includes for the child blocks embedded here
#include "FB_ha_timer.h"
#include "FB_ha_otherthing.h"


union plantInputEvents {
	struct {
		UDINT S2;
		UDINT S3;
	} event;
	
};


union plantOutputEvents {
	struct {
		UDINT update;
	} event;
	
};


typedef struct {
    //input events
	union plantInputEvents inputEvents;

    //output events
	union plantOutputEvents outputEvents;

    //input vars
	
    //output vars
	LREAL x;
    LREAL y;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	ha_timer_t t;
	ha_otherthing_t o;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} plant_t;

//all FBs get a preinit function
int plant_preinit(plant_t  *me);

//all FBs get an init function
int plant_init(plant_t  *me);

//all FBs get a run function
void plant_run(plant_t  *me);

//composite/resource/device FBs get sync functions
void plant_syncOutputEvents(plant_t  *me);
void plant_syncInputEvents(plant_t  *me);

void plant_syncOutputData(plant_t  *me);
void plant_syncInputData(plant_t  *me);



#endif
