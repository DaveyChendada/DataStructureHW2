#include "queue.h"
#include "timer.h"
#include<iostream>
using namespace std;

#define SIZE 10


Queue::Queue(void){
	_data = new float[SIZE];
	size = SIZE;
	_head = 0;
	_tail = 0;
}

bool Queue::IsFull(){
	assert(this != NULL);
	if((_tail + 1 ) % size == _head){
		return true;
	}
	return false;
}

bool Queue::IsEmpty(){
	assert(this != NULL);
	if(_head == _tail){
		return true;
	}
	return false;
}

void Queue::enqueue(float value){
	assert(this != NULL && IsFull == false);
	_data[_tail++] = value;
	_tail %= size;
}

float Queue::dequeue(){
	assert(this != NULL && _data != NULL && IsEmpty() == false);
	float result = _data[_head];
	_head++;
	_head %= size;
	return result;	
}

void Queue::queue_test(int n){
	while(n!=0){
		enqueue(1.01);
		dequeue();
		n--;
	}	
}