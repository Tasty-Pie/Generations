#include <iostream>

#include "linked_stack.h"
using namespace std;

linked_stack::linked_stack() :
		head(nullptr), tail(nullptr), size(0) {
	cout << "Object is constructed" << endl;
}

void linked_stack::push(int newVal) {
	if (size == 0) {
		head = new ListNode(newVal);
		tail = head;
		size = 1;
		return;
	}
	auto newNode = new ListNode(newVal, head);
	head = newNode;
	size++;
}

void linked_stack::pop() {
	if (size == 0) {
		return;
	}
	auto newHead = head->next;
	delete head;
	head = newHead;
	size--;
}

int linked_stack::top() {
	if (size == 0) {
		return -1;
	}
	return head->val;
}

void linked_stack::clear() {
	auto currentElement = head;
	while (currentElement != nullptr) {
		auto toDelete = currentElement;
		currentElement = currentElement->next;
		delete toDelete;
	}
	size = 0;
}

int linked_stack::getSize() {
	return size;
}

void linked_stack::print() {
	auto currentElement = head;
	while (currentElement != nullptr) {
		cout << currentElement->val << " ";
		currentElement = currentElement->next;
	}
	cout << endl;
}

linked_stack::~linked_stack() {
	clear();
	cout << "Object is destroyed" << endl;
}
