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
	ListNode* ptmp;
	ListNode* pnode = head->next;
	while(pnode != head){
		ptmp = pnode;
		pnode = pnode->next;
		delete ptmp;
	}
	delete head;
	head = NULL;
}

void DList::add_to_front(int val){
	if(count==0){
		head->val = val;
		head->prev = head->next = head;
		tail = head;
		count++;
	}
	else if(count==1){
		head->val = val;
		head->prev = head->next = tail;
		tail->next = tail->prev = head;
		count++;
	}
	else{
		ListNode* pnode = head;
		head->val = val;
		head->next->prev = pnode;
		head->next = pnode;
		pnode->prev = head;
		count++;
	}

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
	node->next->prev = node->prev;
	node->prev->next = node->next;
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
	ListNode* node = head;
	int cnt = count;
	while(cnt != 0){
		if(node->val == value){
			return node;
		}
		printf("value is %d\n", node->val);
		node = node->next;
		cnt--;
	}
	return NULL;
}
