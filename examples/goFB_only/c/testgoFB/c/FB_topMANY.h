// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block topMANY
#ifndef TOPMANY_H_
#define TOPMANY_H_

#include "fbtypes.h"
#include "util.h"



//This is a CFB, so we need the #includes for the child blocks embedded here
#include "FB_container_two_basic.h"
#include "FB_container_two_mixed.h"


//this block had no input events


//this block had no output events


typedef struct {
    //input events
	

    //output events
	

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	container_two_basic_t basic;
	container_two_mixed_t mixed;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} topMANY_t;

//all FBs get a preinit function
int topMANY_preinit(topMANY_t  *me);

//all FBs get an init function
int topMANY_init(topMANY_t  *me);

//all FBs get a run function
void topMANY_run(topMANY_t  *me);

//composite/resource/device FBs get sync functions
void topMANY_syncOutputEvents(topMANY_t  *me);
void topMANY_syncInputEvents(topMANY_t  *me);

void topMANY_syncOutputData(topMANY_t  *me);
void topMANY_syncInputData(topMANY_t  *me);



#endif