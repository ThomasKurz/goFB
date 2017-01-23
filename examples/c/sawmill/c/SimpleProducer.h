// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block SimpleProducer
#ifndef SIMPLEPRODUCER_H_
#define SIMPLEPRODUCER_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum SimpleProducer_states { STATE_SimpleProducer_Start, STATE_SimpleProducer_increment, STATE_SimpleProducer_Tx };


union SimpleProducerInputEvents {
	struct {
		UDINT TxSuccessChanged : 1;
	} event;
	UDINT events[1];
};


union SimpleProducerOutputEvents {
	struct {
		UDINT DataPresent : 1;
	} event;
	UDINT events[1];
};


typedef struct {
    //input events
	union SimpleProducerInputEvents inputEvents;

    //output events
	union SimpleProducerOutputEvents outputEvents;

    //input vars
	BOOL TxSuccess;
    
    //output vars
	INT Data;
    
	//any internal vars (BFBs only)
    INT Count;
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum SimpleProducer_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} _SPM SimpleProducer_t;

//all FBs get a preinit function
int SimpleProducer_preinit(SimpleProducer *me);

//all FBs get an init function
int SimpleProducer_init(SimpleProducer *me);

//all FBs get a run function
void SimpleProducer_run(SimpleProducer *me);


//basic FBs have a number of algorithm functions

void SimpleProducer_update_count(SimpleProducer *me);


#endif
