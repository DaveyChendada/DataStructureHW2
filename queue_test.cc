#include "queue.h"
#include "timer.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int
main (int argc, char* argv[])
{
	int n;
	int t;
	stringstream ss1;
	stringstream ss2;
	ss1 << argv[1];
	ss2 << argv[2];
	ss1 >> n;
	ss2 >> t;
	Queue test_queue;
	stopwatch_init();
	struct stopwatch_t* timer = stopwatch_create(); assert(timer);
	stopwatch_start(timer);
	while(t!=0){
		test_queue.queue_test(n);
		t--;
	}
	long double t_ms = stopwatch_stop(timer);
	printf("Average Time: %Lg", t_ms/t);
	stopwatch_destroy(timer);
	return 0;
	
	
}