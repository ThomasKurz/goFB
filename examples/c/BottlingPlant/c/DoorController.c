// This file has been automatically generated by go-iec61499 and should not be edited by hand
// Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499

// This file represents the implementation of the Basic Function Block for DoorController
#include "DoorController.h"

void DoorController_init(struct DoorController *me) {
	//if there are output events, reset them
	DoorReleaseCanister[0] = 0;
	DoorReleaseCanister[1] = 0;
	
	//if there are output vars, reset them
	
	//if there are internal vars, reset them
	
}

void DoorController_run(struct DoorController *me) {

}

