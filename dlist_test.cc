#include "dlist.h"
#include "timer.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

int
main (int argc, char* argv[])
{
	int n;
	int i;
	long double result_t;
	stringstream ss;
	ss << argv[1];
	ss >> n;
	DList list;
	stopwatch_init();
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
		printf("num: %d\n",list.last());
		list.remove(list.search_value(rand_num));
		printf("num: %d\n",list.last());
		long double t_ms = stopwatch_stop(timer);
		result_t += t_ms;
		list.add_to_back(rand_num);
	}
	printf("Time: %Lg\n", result_t/10000);
	stopwatch_destroy(timer);
	return 0;
}