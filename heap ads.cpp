#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class PriorityQueue { // Max heap
private:
	int *treeArray; // parent = i -> child1 = 2*i + 1 and child2 = 2*i + 2
	size_t treeSize;
	size_t treeCapacity;

	bool isLeafNode(size_t i) {
		return 2 * i + 1 >= treeSize;
	}

	void siftDown(size_t i) {
		while (not isLeafNode(i)) {
			size_t j = 2 * i + 1;
			if (j + 1 < treeSize and treeArray[j] < treeArray[j + 1]) {
				j++;
			}
			if (treeArray[i] >= treeArray[j]) {
				break;
			}
			swap(treeArray[i], treeArray[j]);
			i = j;
		}
	}

	void siftUp(size_t i) {
		size_t parent = (i - 1) / 2;
		while (i != 0 and treeArray[parent] < treeArray[i]) {
			swap(treeArray[parent], treeArray[i]);
			i = parent;
			parent = (i - 1) / 2;
		}
	}

public:
	PriorityQueue() :
			treeArray(new int[16]), treeSize(0), treeCapacity(16) {
	}

	void push(int newValue) {
		if (treeSize == treeCapacity) {
			treeCapacity = treeCapacity * 2;
			int *newCopy = new int[treeCapacity];
			for (size_t i = 0; i < treeSize; i++) {
				newCopy[i] = treeArray[i];
			}
			delete[] treeArray;
			treeArray = newCopy;
		}
		treeArray[treeSize] = newValue;
		siftUp(treeSize);
		treeSize++;
	}

	int peek() const { // get_front
		if (treeSize == 0) {
			throw std::runtime_error("Priority queue is empty");
		}
		return treeArray[0];
	}

	void pop() {
		if (treeSize == 0) {
			throw std::runtime_error("Priority queue is empty");
		}
		treeArray[0] = treeArray[treeSize - 1];
		treeSize--;
		siftDown(0);
	}

	void clear() {
		treeSize = 0;
		delete[] treeArray;
		treeArray = new int[16];
		treeCapacity = 16;
	}

	bool isEmpty() const {
		return treeSize == 0;
	}

	size_t size() const {
		return treeSize;
	}

	void print(ostream &out, size_t i = 0, size_t level = 0) const {
		if (i >= treeSize) {
			for (size_t i = 0; i < level; i++) {
				out << "-";
			}
			out << "|null";
			return;
		}
		for (size_t i = 0; i < level; i++) {
			out << "-";
		}
		out << "|";
		out << treeArray[i] << endl;
		print(out, 2 * i + 2, level + 1);
		out << endl;
		print(out, 2 * i + 1, level + 1);
	}

	friend ostream& operator<<(ostream &out,
			const PriorityQueue &queueInstance) {
		queueInstance.print(out);
		return out;
	}

	~PriorityQueue() {
		delete[] treeArray;
	}
};

void printHeap(PriorityQueue &queueInstance) {
	cout << "Heap:\n" << "Size: " << queueInstance.size() << endl
			<< queueInstance << endl << "end Heap" << endl;
}

int main() {
	PriorityQueue testQueue;
	printHeap(testQueue);
	for (int i = 0; i < 20; i++) {
		testQueue.push(rand() % 99);
	}
	printHeap(testQueue);
	for (int i = 0; i < 5; i++) {
		cout << testQueue.peek() << endl;
		testQueue.pop();
	}
	printHeap(testQueue);
	cout << testQueue << endl;
	return 0;
}
