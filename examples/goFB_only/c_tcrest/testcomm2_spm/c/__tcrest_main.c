//This is the main file for the iec61499 network with _TCREST as the top level block

#include "_Core0.h"
#include "_Core1.h"

//put a copy of the top level block into global memory

const int NOC_MASTER = 0;

volatile _UNCACHED int c0init = 0;
volatile _UNCACHED int c1init = 0;

void t0(void* param);
void t1(void* param);

void task0(_Core0_t _SPM * c0);
void task1(_Core1_t _SPM * c1);

int main() {
	mp_init();
	printf("testcomm2_spm startup.\n");
	printf("sizes: %lu, %lu\n", sizeof(_Core0_t), sizeof(_Core1_t));
	printf("Starting c1 and initialising...\n");
	corethread_t core1 = 1;
	corethread_create(&core1, &t0, NULL);
	printf("Started c1\n");
	t1(NULL);
}

void __attribute__ ((noinline)) timed_task0(_Core0_t _SPM * c0) {
	_Core0_syncOutputEvents(c0);
	_Core0_syncInputEvents(c0);

	_Core0_syncOutputData(c0);
	_Core0_syncInputData(c0);

	_Core0_run(c0);
}

void __attribute__ ((noinline)) timed_task1(_Core1_t _SPM * c1) {
	_Core1_syncOutputEvents(c1);
	_Core1_syncInputEvents(c1);
	
	_Core1_syncOutputData(c1);
	_Core1_syncInputData(c1);

	_Core1_run(c1);
}

void task0(_Core0_t _SPM * c0) {
	//task0 runs core0
	unsigned int tickCount = 0;

	unsigned long long start_time;
	unsigned long long end_time;

	do {
		start_time = get_cpu_cycles();

		timed_task0(c0);

		end_time = get_cpu_cycles();
		printf("%4d\t\t%lld\n", tickCount, end_time-start_time-3);

		tickCount++;
	} while(1);
}


void task1(_Core1_t _SPM * c1) {
	//task0 runs core0
	unsigned int tickCount = 0;

	unsigned long long start_time;
	unsigned long long end_time;

	do {
		start_time = get_cpu_cycles();

		timed_task1(c1);

		end_time = get_cpu_cycles();
		printf("%4d\t\t%lld\n", tickCount, end_time-start_time-3);

		tickCount++;
	} while(1);
}


void t1(void* param) {
	//HEX = 1;
	_Core1_t _SPM *c1;
	c1 = SPM_BASE;

	//HEX = 2;
	_Core1_preinit(c1);
	if(_Core1_init(c1) != 0) {
		HEX = 0xF1;
		return;
	}
	mp_init_ports();

	//HEX = 3;

	c1init = 1;
	while(c0init == 0 || c1init == 0);

	//HEX = 4;

	task1(c1);

}


void t0(void* param) {
	//HEX = 5;
	_Core0_t _SPM *c0;
	c0 = SPM_BASE;

	//HEX = 6;

	_Core0_preinit(c0);
	if(_Core0_init(c0) != 0) {
		HEX = 0xF0;
		return;
	}
	mp_init_ports();

	//HEX = 7;

	c0init = 1;
	while(c0init == 0 || c1init == 0);

	//HEX = 8;

	task0(c0);
}