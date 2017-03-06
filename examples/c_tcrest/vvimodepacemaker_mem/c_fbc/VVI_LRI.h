// This file is generated by FBC.

#ifndef VVI_LRI_H_
#define VVI_LRI_H_

#include "fbtypes.h"

typedef union {
    UDINT events;
    struct {
        UDINT VSense; // 
        UDINT LRI_Timer_Timeout; // 
    } event;
} VVI_LRIIEvents;

typedef union {
    UDINT events;
    struct {
        UDINT LRI_Timer_Start; // 
        UDINT LRI_Timer_Stop; // 
        UDINT VPace; // 
    } event;
} VVI_LRIOEvents;

typedef struct {
    UINT _state;
    BOOL _entered;
    VVI_LRIIEvents _input;
    VVI_LRIOEvents _output;
    INT LRI_Timeout_Value; // 
    INT _LRI_Timeout_Value;
} VVI_LRI;

/* Function block initialization function */
void VVI_LRIinit(VVI_LRI* me);

/* Function block execution function */
void VVI_LRIrun(VVI_LRI* me);

/* ECC algorithms */
void VVI_LRI_LRI_Set_Timeout_Value(VVI_LRI* me);

#endif // VVI_LRI_H_
