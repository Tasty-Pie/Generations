#pragma once

#ifndef LINKED_STACK_H_
#define LINKED_STACK_H_

#include "mystack.h"

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int newVal = 0, ListNode *newNext = nullptr) : // default arguments
			val(newVal), next(newNext) {
	}
};

class linked_stack {
private:
	ListNode *head; // member variables or attributes
	ListNode *tail;
	int size;
public:
	linked_stack();
	void push(int newVal); // function declaration or interface. It's job is to push a new value to stack
	void pop();
	int top();
	void clear();
	int getSize();
	void print();
	~linked_stack();
};

#endif
