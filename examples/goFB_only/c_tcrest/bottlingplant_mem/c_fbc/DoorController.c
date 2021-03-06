// This file is generated by FBC.

#include "DoorController.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void DoorControllerinit(DoorController* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_input.event.ReleaseDoorOverride = 0;
    me->_input.event.BottlingDone = 0;
    me->_input.event.EmergencyStopChanged = 0;

    me->_output.event.DoorReleaseCanister = 0;
}

/* Function block execution function */
void DoorControllerrun(DoorController* me)
{
    int _PRET_BOUND_i = 0;
    me->_output.event.DoorReleaseCanister = 0;


        if (me->_input.event.EmergencyStopChanged) {
            me->EmergencyStop = me->_EmergencyStop;
        }
    
	#pragma loopbound min 1 max 2
    for (_PRET_BOUND_i = 0; _PRET_BOUND_i < 2; _PRET_BOUND_i++) {
    asm("#@PRET_Bound 2");
        switch (me->_state) {
        asm("#@PRET_switch_start 1");
            case 0:
                // State: E_Stop
                if (!me->_entered) {
                    me->_entered = true;
                    break;
                }
                else {
                    if (me->_input.event.EmergencyStopChanged && (! me->EmergencyStop)) {
                        me->_state = 1;
                        me->_entered = false;
                        continue;
                    }
                    break;
                }
                break;
            case 1:
                // State: Await
                if (!me->_entered) {
                    me->_entered = true;
                    break;
                }
                else {
                    if (me->_input.event.ReleaseDoorOverride || me->_input.event.BottlingDone) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                    break;
                }
                break;
            case 2:
                // State: Run
                if (!me->_entered) {
                    me->_output.event.DoorReleaseCanister = 1;
                    me->_entered = true;
                    break;
                }
                else {
                    if (me->_input.event.EmergencyStopChanged && (me->EmergencyStop)) {
                        me->_state = 0;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->_input.event.ReleaseDoorOverride || me->_input.event.BottlingDone) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                    break;
                }
                break;
        }
        break;
    asm("#@PRET_switch_end 1");
    }

    me->_input.event.ReleaseDoorOverride = 0;
    me->_input.event.BottlingDone = 0;
    me->_input.event.EmergencyStopChanged = 0;
}

