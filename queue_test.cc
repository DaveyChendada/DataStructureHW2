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
	
	cout<<"n="<<n<<endl;
	cout<<"t="<<t<<endl;
}