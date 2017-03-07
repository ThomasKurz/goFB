// This file has been automatically generated by goFB
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

//This is the main file for the iec61499 network with FlexPRET as the top level block

#include "FlexPRET.h"

//put a copy of the top level block into global memory
FlexPRET_t myFlexPRET;

int main() {
	if(FlexPRET_preinit(&myFlexPRET) != 0) {
		printf("Failed to preinitialize.");
		return 1;
	}
	if(FlexPRET_init(&myFlexPRET) != 0) {
		printf("Failed to initialize.");
		return 1;
	}

	printf("Top: %20s   Size: %lu\n", "FlexPRET", sizeof(myFlexPRET));

	int tickNum = 0;
	do {
		printf("=====TICK %i=====\n",tickNum);
		FlexPRET_syncOutputEvents(&myFlexPRET);
		FlexPRET_syncInputEvents(&myFlexPRET);

		FlexPRET_syncOutputData(&myFlexPRET);
		FlexPRET_syncInputData(&myFlexPRET);
		
		FlexPRET_run(&myFlexPRET);
	} while(tickNum++ < 10);

	return 0;
}

