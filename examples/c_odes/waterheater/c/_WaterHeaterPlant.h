// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block _WaterHeaterPlant
#ifndef _WATERHEATERPLANT_H_
#define _WATERHEATERPLANT_H_

#include "fbtypes.h"



//This is a CFB, so we need the #includes for the child blocks embedded here
#include "WaterHeaterPlantODE.h"
#include "interResourceTxLReal.h"
#include "interResourceRxBool.h"
#include "TickGen.h"


//this block had no input events


//this block had no output events


typedef struct {
    //input events
	

    //output events
	

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	WaterHeaterPlantODE_t waterHeaterPlantODE;
	interResourceTxLReal_t t_tx;
	interResourceRxBool_t heat_rx;
	TickGen_t tickgen;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} _WaterHeaterPlant_t;

//all FBs get a preinit function
int _WaterHeaterPlant_preinit(_WaterHeaterPlant_t  *me);

//all FBs get an init function
int _WaterHeaterPlant_init(_WaterHeaterPlant_t  *me);

//all FBs get a run function
void _WaterHeaterPlant_run(_WaterHeaterPlant_t  *me);

//composite/resource/device FBs get sync functions
void _WaterHeaterPlant_syncOutputEvents(_WaterHeaterPlant_t  *me);
void _WaterHeaterPlant_syncInputEvents(_WaterHeaterPlant_t  *me);

void _WaterHeaterPlant_syncOutputData(_WaterHeaterPlant_t  *me);
void _WaterHeaterPlant_syncInputData(_WaterHeaterPlant_t  *me);



#endif
