#include <bits/stdc++.h>
using namespace std;

class array_queue {
private:
	int *arr;
	int size;
	int capacity;
	int frontIndex;
	int backIndex;
public:
	array_queue() :
			arr(new int[4]), size(0), capacity(4), frontIndex(0), backIndex(-1) {
	}

	void push(int newValue) {
		if (size == capacity) {
			int newCapacity = capacity * 2;
			int *newArr = new int[newCapacity];
			for (int i = 0, index = frontIndex; i < size;
					i++, index = (index + 1) % capacity) {
				newArr[i] = arr[index];
			}
			frontIndex = 0;
			backIndex = frontIndex + size - 1;
			capacity = newCapacity;
			delete arr;
			arr = newArr;
		}
		backIndex = (backIndex + 1) % capacity;
		arr[backIndex] = newValue;
		size++;
	}

	void pop() {
		if (size == 0) {
			return;
		}
		frontIndex++;
		size--;
	}

	int get_front() {
		if (size == 0) {
			return -1;
		}
		return arr[frontIndex];
	}

	int get_back() {
		if (size == 0) {
			return -1;
		}
		return arr[backIndex];
	}

	void clear() {
		size = 0;
		frontIndex = 0;
		backIndex = -1;
	}

	int get_size() {
		return size;
	}

	void print() {
		for (int i = 0, index = frontIndex; i < size;
				i++, index = (index + 1) % capacity) {
			cout << arr[index] << " ";
		}
		cout << endl;
	}

	int get_capacity() {
		return capacity;
	}

	~array_queue() {
		delete[] arr;
	}
};

int main() {
	array_queue myQ;
	cout << myQ.get_capacity() << endl;
	for (int i = 1; i < 1000; i *= 2) {
		myQ.push(i);
	}
	myQ.print();
	cout << myQ.get_capacity() << endl;
	for (int i = 0; i < 5; i++) {
		myQ.pop();
	}
	myQ.print();
	cout << myQ.get_capacity() << endl;
	for (int i = 1; i < 10000; i *= 2) {
		myQ.push(i);
	}
	myQ.print();
	cout << myQ.get_capacity() << endl;
	return 0;
}
