// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for IOManager
#include "IOManager.h"


/* IOManager_preinit() is required to be called to 
 * initialise an instance of IOManager. 
 * It sets all I/O values to zero.
 */
int IOManager_preinit(IOManager_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.DoorReleaseCanister = 0;
	me->inputEvents.event.ConveyorChanged = 0;
	me->inputEvents.event.InjectorPositionChanged = 0;
	me->inputEvents.event.InjectorControlsChanged = 0;
	me->inputEvents.event.FillContentsChanged = 0;
	me->inputEvents.event.StartVacuumTimer = 0;
	me->inputEvents.event.GoRejectArm = 0;
	me->inputEvents.event.CanisterCountChanged = 0;
	me->inputEvents.event.InjectDone = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.InjectorArmFinishMovement = 0;
	me->outputEvents.event.EmergencyStopChanged = 0;
	me->outputEvents.event.CanisterPressureChanged = 0;
	me->outputEvents.event.FillContentsAvailableChanged = 0;
	me->outputEvents.event.LasersChanged = 0;
	me->outputEvents.event.DoorOverride = 0;
	me->outputEvents.event.VacuumTimerElapsed = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	me->EmergencyStopped = 1;
	me->BottlePositions[0] = 0;
	me->BottlePositions[1] = 0;
	me->BottlePositions[2] = 0;
	me->BottlePositions[3] = 0;
	me->BottlesActive[0] = 0;
	me->BottlesActive[1] = 0;
	me->BottlesActive[2] = 0;
	me->BottlesActive[3] = 0;
	me->NextBottle = 0;
	me->InternalConveyorSpeed = 0;
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_IOManager_Start;
	

	return 0;
}

/* IOManager_init() is required to be called to 
 * set up an instance of IOManager. 
 * It passes around configuration data.
 */
int IOManager_init(IOManager_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void IOManager_IOAlgorithm(IOManager_t  *me) {
#define NUM_BOTTLES 4



//reset all the things
me->EmergencyStop = 0;
me->CanisterPressure = 255;
me->FillContentsAvailable = 255;
me->DoorSiteLaser = 0;
me->InjectSiteLaser = 0;
me->RejectSiteLaser = 0;
me->RejectBinLaser = 0;
me->AcceptBinLaser = 0;


////printf("=====new tick\n");

//continue progress

	
// #pragma loopbound min 1 max 4
// for(int i = 0; i < 4; i++) {
// 	if(me->ConveyorSpeed) {
// 		if(me->BottlesActive[i]) {
// 			me->BottlePositions[i] += me->InternalConveyorSpeed;
// 			//printf("IO: Canister %i moves to %i\n", i, me->BottlePositions[i]);
			
// 			if(me->BottlePositions[i] == 5) {
// 				//printf("IO: Canister %i at 5, triggering InjectSiteLaser\n", i);
// 				me->outputEvents.event.LasersChanged = 1;
// 				me->InjectSiteLaser = 1;
// 			} else if(me->BottlePositions[i] == 10) {
// 				//printf("IO: Canister %i at 10, triggering RejectSiteLaser\n", i);
// 				me->outputEvents.event.LasersChanged = 1;
// 				me->RejectSiteLaser = 1;
// 			} else if(me->BottlePositions[i] == 20) {
// 				//printf("IO: Canister %i at 20, falls off conveyor, triggering AcceptBinLaser\n", i);
// 				me->outputEvents.event.LasersChanged = 1;
// 				me->AcceptBinLaser = 1;
// 				me->BottlesActive[i] = 0;
// 				me->BottlePositions[i] = 0;
// 			} 
			
// 			if(me->inputEvents.event.GoRejectArm && (me->BottlePositions[i] == 10 || me->BottlePositions[i] == 11 || me->BottlePositions[i] == 12)) {
// 				//printf("IO: Go Reject Arm. Canister %i knocked from conveyor.\n", i);
// 				//progress = 0;
// 				me->outputEvents.event.LasersChanged = 1;
// 				me->RejectBinLaser = 1;
// 				me->BottlesActive[i] = 0;
// 				me->BottlePositions[i] = 0;
// 			}
// 		}
// 	}
// }

	if(me->ConveyorSpeed) {
		if(me->BottlesActive[1]) {
			me->BottlePositions[1] += me->InternalConveyorSpeed;
			//printf("IO: Canister %i moves to %i\n", i, me->BottlePositions[1]);
			
			if(me->BottlePositions[1] == 5) {
				//printf("IO: Canister %i at 5, triggering InjectSiteLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->InjectSiteLaser = 1;
			} else if(me->BottlePositions[1] == 10) {
				//printf("IO: Canister %i at 10, triggering RejectSiteLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->RejectSiteLaser = 1;
			} else if(me->BottlePositions[1] == 20) {
				//printf("IO: Canister %i at 20, falls off conveyor, triggering AcceptBinLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->AcceptBinLaser = 1;
				me->BottlesActive[1] = 0;
				me->BottlePositions[1] = 0;
			} 
			
			if(me->inputEvents.event.GoRejectArm && (me->BottlePositions[1] == 10 || me->BottlePositions[1] == 11 || me->BottlePositions[1] == 12)) {
				//printf("IO: Go Reject Arm. Canister %i knocked from conveyor.\n", i);
				//progress = 0;
				me->outputEvents.event.LasersChanged = 1;
				me->RejectBinLaser = 1;
				me->BottlesActive[1] = 0;
				me->BottlePositions[1] = 0;
			}
		}
	}

	if(me->ConveyorSpeed) {
		if(me->BottlesActive[2]) {
			me->BottlePositions[2] += me->InternalConveyorSpeed;
			//printf("IO: Canister %i moves to %i\n", i, me->BottlePositions[2]);
			
			if(me->BottlePositions[2] == 5) {
				//printf("IO: Canister %i at 5, triggering InjectSiteLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->InjectSiteLaser = 1;
			} else if(me->BottlePositions[2] == 10) {
				//printf("IO: Canister %i at 10, triggering RejectSiteLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->RejectSiteLaser = 1;
			} else if(me->BottlePositions[2] == 20) {
				//printf("IO: Canister %i at 20, falls off conveyor, triggering AcceptBinLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->AcceptBinLaser = 1;
				me->BottlesActive[2] = 0;
				me->BottlePositions[2] = 0;
			} 
			
			if(me->inputEvents.event.GoRejectArm && (me->BottlePositions[2] == 10 || me->BottlePositions[2] == 11 || me->BottlePositions[2] == 12)) {
				//printf("IO: Go Reject Arm. Canister %i knocked from conveyor.\n", i);
				//progress = 0;
				me->outputEvents.event.LasersChanged = 1;
				me->RejectBinLaser = 1;
				me->BottlesActive[2] = 0;
				me->BottlePositions[2] = 0;
			}
		}
	}

	if(me->ConveyorSpeed) {
		if(me->BottlesActive[3]) {
			me->BottlePositions[3] += me->InternalConveyorSpeed;
			//printf("IO: Canister %i moves to %i\n", i, me->BottlePositions[3]);
			
			if(me->BottlePositions[3] == 5) {
				//printf("IO: Canister %i at 5, triggering InjectSiteLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->InjectSiteLaser = 1;
			} else if(me->BottlePositions[3] == 10) {
				//printf("IO: Canister %i at 10, triggering RejectSiteLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->RejectSiteLaser = 1;
			} else if(me->BottlePositions[3] == 20) {
				//printf("IO: Canister %i at 20, falls off conveyor, triggering AcceptBinLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->AcceptBinLaser = 1;
				me->BottlesActive[3] = 0;
				me->BottlePositions[3] = 0;
			} 
			
			if(me->inputEvents.event.GoRejectArm && (me->BottlePositions[3] == 10 || me->BottlePositions[3] == 11 || me->BottlePositions[3] == 12)) {
				//printf("IO: Go Reject Arm. Canister %i knocked from conveyor.\n", i);
				//progress = 0;
				me->outputEvents.event.LasersChanged = 1;
				me->RejectBinLaser = 1;
				me->BottlesActive[3] = 0;
				me->BottlePositions[3] = 0;
			}
		}
	}

	if(me->ConveyorSpeed) {
		if(me->BottlesActive[0]) {
			me->BottlePositions[0] += me->InternalConveyorSpeed;
			//printf("IO: Canister %i moves to %i\n", i, me->BottlePositions[0]);
			
			if(me->BottlePositions[0] == 5) {
				//printf("IO: Canister %i at 5, triggering InjectSiteLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->InjectSiteLaser = 1;
			} else if(me->BottlePositions[0] == 10) {
				//printf("IO: Canister %i at 10, triggering RejectSiteLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->RejectSiteLaser = 1;
			} else if(me->BottlePositions[0] == 20) {
				//printf("IO: Canister %i at 20, falls off conveyor, triggering AcceptBinLaser\n", i);
				me->outputEvents.event.LasersChanged = 1;
				me->AcceptBinLaser = 1;
				me->BottlesActive[0] = 0;
				me->BottlePositions[0] = 0;
			} 
			
			if(me->inputEvents.event.GoRejectArm && (me->BottlePositions[0] == 10 || me->BottlePositions[0] == 11 || me->BottlePositions[0] == 12)) {
				//printf("IO: Go Reject Arm. Canister %i knocked from conveyor.\n", i);
				//progress = 0;
				me->outputEvents.event.LasersChanged = 1;
				me->RejectBinLaser = 1;
				me->BottlesActive[0] = 0;
				me->BottlePositions[0] = 0;
			}
		}
	}

//if(canisterProgress == 25) {
//	//printf("Progress at 25, halting\n");
//	while(1);
//}

if(me->inputEvents.event.InjectDone) {
	//printf("IO: Inject done\n");
}



if(me->EmergencyStopped == 1) {
	//printf("IO: Releasing emergency stop\n");
	me->outputEvents.event.EmergencyStopChanged = 1;
	me->EmergencyStop = 0;
	me->EmergencyStopped++;
} else {
	
	if(me->inputEvents.event.DoorReleaseCanister) {
		//printf("IO: Door released. Adding canister %i\n", me->NextBottle);

		me->outputEvents.event.LasersChanged = 1;
		me->DoorSiteLaser = 1;
			
		me->BottlesActive[me->NextBottle] = 1;

		me->NextBottle++;
		me->NextBottle = me->NextBottle % 4;
		
	}
	if(me->inputEvents.event.InjectorPositionChanged) {
		//printf("IO: Injector position changed. Setting move finished.\n");
		me->outputEvents.event.InjectorArmFinishMovement = 1;
	}

	if(me->inputEvents.event.ConveyorChanged) {
		me->InternalConveyorSpeed = me->ConveyorSpeed;
		//printf("IO: Setting conveyor movement to %i\n", me->InternalConveyorSpeed);
	}

	

	if(me->inputEvents.event.InjectorControlsChanged) {
		//printf("IO: Injector controls changed. Now they are Vac: %1i Val: %1i Pmp: %1i\n", me->InjectorVacuumRun, me->InjectorContentsValveOpen, me->InjectorPressurePumpRun);
		if(me->InjectorVacuumRun) {
			//printf("IO: Due to vacuum, changing canister pressure to 5.\n");
			me->CanisterPressure = 5;
			me->outputEvents.event.CanisterPressureChanged = 1;
		}
		if(me->InjectorContentsValveOpen) {
			//printf("IO: Contents valve now open. Pressure changes slightly, sucking in contents.\n");
			me->CanisterPressure = 20;
			me->outputEvents.event.CanisterPressureChanged = 1;
		}
		if(me->InjectorPressurePumpRun) {
			//printf("IO: Due to pressure pump, changing canister pressure to 250.\n");
			me->CanisterPressure = 250;
			me->outputEvents.event.CanisterPressureChanged = 1;
		}
	}
	
	if(me->inputEvents.event.FillContentsChanged) {
		//printf("IO: Fill contents changed.\n");
	}

	if(me->inputEvents.event.StartVacuumTimer) {
		//printf("IO: Start vacuum timer.\n");//Elapsing timer.\n");
		//me->outputEvents.event.VacuumTimerElapsed = 1;
	}

	

	if(me->inputEvents.event.CanisterCountChanged) {
		//printf("IO: Canister count changed. New value: %i\n", me->CanisterCount);
	}


}



}



/* IOManager_run() executes a single tick of an
 * instance of IOManager according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void IOManager_run(IOManager_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.InjectorArmFinishMovement = 0;
	me->outputEvents.event.EmergencyStopChanged = 0;
	me->outputEvents.event.CanisterPressureChanged = 0;
	me->outputEvents.event.FillContentsAvailableChanged = 0;
	me->outputEvents.event.LasersChanged = 0;
	me->outputEvents.event.DoorOverride = 0;
	me->outputEvents.event.VacuumTimerElapsed = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_IOManager_Start:
			if(true) {
				me->_state = STATE_IOManager_Start;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_IOManager_Start:
			IOManager_IOAlgorithm(me);
			me->outputEvents.event.EmergencyStopChanged = 1;
			break;

		
		}
	}

	me->_trigger = false;
}


