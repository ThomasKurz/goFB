// This file has been automatically generated by goFB
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

//This is the main file for the iec61499 network with _WaterHeaterPlant as the top level block

#include "_WaterHeaterPlant.h"

//put a copy of the top level block into global memory
_WaterHeaterPlant_t my_WaterHeaterPlant;

int main() {
	if(_WaterHeaterPlant_preinit(&my_WaterHeaterPlant) != 0) {
		printf("Failed to preinitialize.");
		return 1;
	}
	if(_WaterHeaterPlant_init(&my_WaterHeaterPlant) != 0) {
		printf("Failed to initialize.");
		return 1;
	}

	printf("Top: %20s   Size: %lu\n", "_WaterHeaterPlant", sizeof(my_WaterHeaterPlant));

	int tickNum = 0;
	do {
		//printf("=====TICK %i=====\n",tickNum);
		_WaterHeaterPlant_syncOutputEvents(&my_WaterHeaterPlant);
		_WaterHeaterPlant_syncInputEvents(&my_WaterHeaterPlant);

		_WaterHeaterPlant_syncOutputData(&my_WaterHeaterPlant);
		_WaterHeaterPlant_syncInputData(&my_WaterHeaterPlant);
		
		_WaterHeaterPlant_run(&my_WaterHeaterPlant);
	} while(tickNum++ < 500);

	return 0;
}

