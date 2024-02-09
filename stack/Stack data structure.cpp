#include <iostream>
#include "mystack.h"
class stack {
private:
	int *array; // member variables or attributes
	int size;
	int capacity;
public:
	stack();
	void push(int newVal); // function declaration or interface. It's job is to push a new value to stack
	void pop();
	int top();
	void clear();
	int getSize();
	void print();
	~stack();
};

#include "linked_stack.h"

// MACROS
#define MAX_ARRAY_SIZE 100
const int max_array_size = 100;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main() {
	int val = (((1) < (23)) ? (1) : (23));

	stack s;
	for (int i = 1; i < 1000; i *= 2) {
		s.push(i);
	}
	s.print();

#if 0
	linked_stack ls;
	for (int i = 1; i < 1000; i *= 2) {
		ls.push(i);
	}
	ls.print();
#endif

	return 0;
}
