// This file is generated by FBC.

#ifndef UNITCONTROL_H_
#define UNITCONTROL_H_

#include "fbtypes.h"

typedef union {
    UDINT events;
    struct {
        UDINT TimerExpired : 1; // 
        UDINT Request : 1; // 
        UDINT FloorSensor : 1; // 
    } event;
} UnitControlIEvents;

typedef union {
    UDINT events;
    struct {
        UDINT MotorDirectionUp : 1; // 
        UDINT MotorDirectionDown : 1; // 
        UDINT MotorDirectionIdle : 1; // 
        UDINT DoorOpen : 1; // 
        UDINT DoorClose : 1; // 
        UDINT StartTimer : 1; // 
        UDINT StoppedAtFloor : 1; // 
    } event;
} UnitControlOEvents;

typedef struct {
    UINT _state;
    BOOL _entered;
    UnitControlIEvents _input;
    INT FloorSensorValue; // 
    INT _FloorSensorValue;
    INT RequestValue; // 
    INT _RequestValue;
    UnitControlOEvents _output;
    INT StoppedAtFloorValue; // 
    INT _StoppedAtFloorValue;
} UnitControl;

/* Function block initialization function */
void UnitControlinit(UnitControl* me);

/* Function block execution function */
void UnitControlrun(UnitControl* me);

/* ECC algorithms */
void UnitControl_UpdateStoppedAtFloor(UnitControl* me);
void UnitControl_ResetStoppedAtFloor(UnitControl* me);

#endif // UNITCONTROL_H_
