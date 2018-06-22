// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for AB5Controller
#include "FB_AB5Controller.h"


/* AB5Controller_preinit() is required to be called to 
 * initialise an instance of AB5Controller. 
 * It sets all I/O values to zero.
 */
int AB5Controller_preinit(AB5Controller_t  *me) {
	

	//reset the input events
	me->inputEvents.event.A = 0;
	
	//reset the output events
	me->outputEvents.event.B = 0;
	
	//set any input vars with default values
	
	//set any output vars with default values
	
	//set any internal vars with default values
	
	
	
	
	

	
	
	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	me->_state = STATE_AB5Controller_unknown;
	me->_trigger = true;
	
	
	

	//this block has policies
	
	me->_policy_AB5_state = POLICY_STATE_AB5Controller_AB5_s0;
	//input policy internal vars
	//output policy internal vars
	
	me->v = 0;
	
	
	
	

	return 0;
}

/* AB5Controller_init() is required to be called to 
 * set up an instance of AB5Controller. 
 * It passes around configuration data.
 */
int AB5Controller_init(AB5Controller_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	
	

	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//no algorithms were present for this function block


/* AB5Controller_run() executes a single tick of an
 * instance of AB5Controller according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will already be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void AB5Controller_run(AB5Controller_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.B = 0;
	
	
	
	//input policies
	
	//INPUT POLICY AB5 BEGIN 
		switch(me->_policy_AB5_state) {
			case POLICY_STATE_AB5Controller_AB5_s0:
				
				if( !me->inputEvents.event.A) {
					//transition s0 -> violation on !A
					//select a transition to solve the problem
					
					//Selected non-violation transition "s0 -> s0 on !A" which has an equivalent guard, so no action is required
					
				} 
				if(me->inputEvents.event.A) {
					//transition s0 -> violation on A
					//select a transition to solve the problem
					
					//Selected non-violation transition "s0 -> s1 on A" which has an equivalent guard, so no action is required
					
				} 
				
				break;

			case POLICY_STATE_AB5Controller_AB5_s1:
				
				if(me->v >= 5) {
					//transition s1 -> violation on v >= 5
					//select a transition to solve the problem
					
					//Selected non-violation transition "s1 -> s0 on !A" and action is required
					me->inputEvents.event.A = 0;
				} 
				if(me->inputEvents.event.A) {
					//transition s1 -> violation on A
					//select a transition to solve the problem
					
					//Selected non-violation transition "s1 -> s0 on !A" and action is required
					me->inputEvents.event.A = 0;
				} 
				
				break;

			
		}
	
	//INPUT POLICY AB5 END
	


	
	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		
		default: 
			break;
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		
		default: 
			break;
		}
	}

	me->_trigger = false;

	
	//output policies
	
	//OUTPUT POLICY AB5 BEGIN 
		switch(me->_policy_AB5_state) {
			case POLICY_STATE_AB5Controller_AB5_s0:
				
				if( !me->inputEvents.event.A && me->outputEvents.event.B) {
					//transition s0 -> violation on !A && B
					//select a transition to solve the problem
					
					//Selected non-violation transition "s0 -> s0 on !A && !B" and action is required
					me->outputEvents.event.B = 0;
				} 
				if(me->inputEvents.event.A && me->outputEvents.event.B) {
					//transition s0 -> violation on A && B
					//select a transition to solve the problem
					
					//Selected non-violation transition "s0 -> s0 on !A && !B" and action is required
					me->outputEvents.event.B = 0;
				} 

				break;

			case POLICY_STATE_AB5Controller_AB5_s1:
				
				if(me->v >= 5) {
					//transition s1 -> violation on v >= 5
					//select a transition to solve the problem
					
					//Selected non-violation transition "s1 -> s0 on !A && B" and action is required
					me->outputEvents.event.B = 1;
				} 
				if(me->inputEvents.event.A && me->outputEvents.event.B) {
					//transition s1 -> violation on A && B
					//select a transition to solve the problem
					
					//Selected non-violation transition "s1 -> s0 on !A && B" and action is required
					me->outputEvents.event.B = 1;
				} 
				if(me->inputEvents.event.A && !me->outputEvents.event.B) {
					//transition s1 -> violation on A && !B
					//select a transition to solve the problem
					
					//Selected non-violation transition "s1 -> s0 on !A && B" and action is required
					me->outputEvents.event.B = 1;
				} 

				break;

			
		}

		//advance timers
		
		me->v++;

		//select transition to advance state
		switch(me->_policy_AB5_state) {
			case POLICY_STATE_AB5Controller_AB5_s0:
				
				if( !me->inputEvents.event.A && !me->outputEvents.event.B) {
					//transition s0 -> s0 on !A && !B
					me->_policy_AB5_state = POLICY_STATE_AB5Controller_AB5_s0;
				} 
				if(me->inputEvents.event.A && !me->outputEvents.event.B) {
					//transition s0 -> s1 on A && !B
					me->_policy_AB5_state = POLICY_STATE_AB5Controller_AB5_s1;
				} 
				
				break;

			case POLICY_STATE_AB5Controller_AB5_s1:
				
				if( !me->inputEvents.event.A && !me->outputEvents.event.B && me->v < 5) {
					//transition s1 -> s1 on !A && !B && v < 5
					me->_policy_AB5_state = POLICY_STATE_AB5Controller_AB5_s1;
				} 
				if( !me->inputEvents.event.A && me->outputEvents.event.B) {
					//transition s1 -> s0 on !A && B
					me->_policy_AB5_state = POLICY_STATE_AB5Controller_AB5_s0;
				} 
				
				break;

			
		}
	
	//OUTPUT POLICY AB5 END
	


	//Ensure input events are cleared
	me->inputEvents.event.A = 0;
	
}


