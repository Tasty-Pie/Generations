#include <iostream>

#include "mystack.h"
using namespace std;

stack::stack() :
		array(new int[8]), size(0), capacity(8) {
	cout << "Object is constructed" << endl;
}

void stack::push(int newVal) {
	if (size == capacity) {
		int newCapacity = 2 * capacity;
		int *newArray = new int[newCapacity];
		for (int i = 0; i < size; i++) {
			newArray[i] = array[i];
		}
		delete[] array;
		array = newArray;
		capacity = newCapacity;
	}
	array[size] = newVal;
	size++;
}

void stack::pop() {
	if (size == 0) {
		return;
	}
	size--;
}

int stack::top() {
	if (size == 0) {
		return -1;
	}
	return array[size - 1];
}

void stack::clear() {
	size = 0;
}

int stack::getSize() {
	return size;
}

void stack::print() {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

stack::~stack() {
	delete[] array;
	cout << "Object is destroyed" << endl;
}
