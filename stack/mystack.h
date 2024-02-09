#ifndef MYSTACK_H_  // preprocessing
#define MYSTACK_H_

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
// LIFO data structure -> Last in first out

#endif /* MYSTACK_H_ */
