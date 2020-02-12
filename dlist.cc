#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

DList::DList(){
	head = new ListNode();
	tail = head;
	count = 0;
}

DList::~DList(){
	while(count>0)
		remove(tail);
	delete head;
}

void DList::add_to_front(int val){
	ListNode* p = new ListNode();
	p->val = val;
	head->next->prev = p;
	p->next = head->next;
	p->prev = head;
	head->next = p;
	count++;
}

void DList::add_to_back(int val){
	ListNode* p = new ListNode();
	p->val = val;
	tail->next = p;
	p->prev = tail;
	tail = p;
	count++;
}

int DList::first(){
	int result = head->val;
	return result;
}

int DList::last(){
	int result = tail->val;
	return result;
}

void DList::remove(ListNode* node){
	ListNode* prev = node->prev;
	if(node == tail){
		prev->next = NULL;
		tail = prev;
	}
	else{
		prev->next = node->next;
		node->next->prev = prev;
	}
	delete node;
	count--;
}

ListNode* DList::previous(ListNode* node){
	return node->prev;
}

ListNode* DList::next(ListNode* node){
	return node->next;
}

ListNode* DList::search_value(int value){
	ListNode* node = head->next;
	int cnt = count;
	while(node!=NULL){
		printf("value is %d\n", node->val);
		if(node->val == value){
			return node;
		}
		node = node->next;
	}
	return NULL;
}
