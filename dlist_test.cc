#include "dlist.h"
#include "timer.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int
main (int argc, char* argv[])
{
	int n;
	int i;
	unsigned seed;
	long double result_t = 0;
	stringstream ss;
	ss << argv[1];
	ss >> n;
	DList list;
	stopwatch_init();
	seed = time(0);
	srand(seed);
	int cnt = n;
	while(cnt!=0){
		list.add_to_back(cnt);
		cnt--;
		printf("num: %d\n",list.last());
	}
	struct stopwatch_t* timer = stopwatch_create(); assert(timer);
	for(i=0;i<100;i++){
		printf("num: %d\n",list.last());
		stopwatch_start(timer);
		int rand_num = rand()%n + 1;
		printf("rand_num: %d\n",rand_num);
		list.remove(list.search_value(rand_num));
		printf("num: %d\n",list.last());
		long double t_ms = stopwatch_stop(timer);
		result_t = result_t + t_ms;
		printf("time_num: %Lg\n",result_t);
		list.add_to_back(rand_num);
		printf("num: %d\n",list.last());
	}
	printf("Time: %Lg\n", result_t/100);
	stopwatch_destroy(timer);
	return 0;
}