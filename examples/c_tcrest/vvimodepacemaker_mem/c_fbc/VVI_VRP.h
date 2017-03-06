// This file is generated by FBC.

#ifndef VVI_VRP_H_
#define VVI_VRP_H_

#include "fbtypes.h"

typedef union {
    struct {
        UDINT VPulse ; // 
        UDINT VPace ; // 
        UDINT VRP_Timer_Timeout ; // 
    } event;
} VVI_VRPIEvents;

typedef union {
    struct {
        UDINT VRP_Start_Timer ; // 
        UDINT VSense ; // 
        UDINT VRefractory ; // 
    } event;
} VVI_VRPOEvents;

typedef struct {
    UINT _state;
    BOOL _entered;
    VVI_VRPIEvents _input;
    VVI_VRPOEvents _output;
    INT VRP_Timeout_Value; // 
    INT _VRP_Timeout_Value;
} VVI_VRP;

/* Function block initialization function */
void VVI_VRPinit(VVI_VRP* me);

/* Function block execution function */
void VVI_VRPrun(VVI_VRP* me);

/* ECC algorithms */
void VVI_VRP_VRP_Set_Timeout_Value(VVI_VRP* me);

#endif // VVI_VRP_H_