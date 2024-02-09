#include <bits/stdc++.h>
using namespace std;

// C-style
struct Person { // Python/Java data class
	string name; // attribute/member variables
	int age;
	double weight;
	char gender;
};

void introduceYourself(const Person *p_ptr) {
	cout << "Hello, my name is " << p_ptr->name << ". I'm " << (*p_ptr).age
			<< " years old." << endl;
}

void setNewName(Person &p, string newName) {
	p.name = newName;
}

void celebrateBirthday(Person &p) {
	p.age++;
	cout << "Today is my birthday, I\'m now " << p.age << " years old." << endl;
}

string getGender(const Person &p) {
	if (p.gender == 'M' or p.gender == 'm') {
		return "Male";
	} else if (p.gender == 'F' or p.gender == 'f') {
		return "Female";
	}
	return "Unknown";
}

void printPerson(Person p) {
	cout << "Name: " << p.name << endl;
	cout << "Age: " << p.age << endl;
	cout << "Weight:" << p.weight << endl;
	cout << "Gender: " << p.gender << endl;
}

void printVector(const vector<int> &vec) {
	for (int elem : vec) { //C++, Java, Python range based for loop
		cout << elem << " ";
	}
	cout << endl;
}

//OOP style
#if 0
class Person {
private:
	string name; // attribute/member variables
	int age;
	double weight;
	char gender;

	Person() {
		;
	}

public: // Getters and Setters

	void introduceYourself() const {  // member functions
		cout << "Hello, my name is " << name << ". I'm " << age << " years old."
				<< endl;
	}

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	void celebrateBirthday() {
		age++;
		cout << "Today is my birthday, I\'m now " << age << " years old."
				<< endl;
	}

	string getGender() { // this and pointers
		if (gender == 'M' or gender == 'm') {
			return "Male";
		} else if (gender == 'F' or gender == 'f') {
			return "Female";
		}
		return "Unknown";
	}
};
#endif

// OOP principles
// Abstraction
// Encapsulation
// Polymorphism
// Inheritance

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};

class Map {
	TreeNode *root;

};

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int newVal) { // function overloading
		val = newVal;
		next = nullptr;
	}

	ListNode(int newVal, ListNode *newNext) {
		val = newVal;
		next = newNext;
	}
};

struct LinkedList {
private:
	ListNode *head;
	int size;
public:
	LinkedList() {
		head = nullptr;
		size = 0;
	}

	void addNewElement(int newVal) {
		head = new ListNode(newVal, head);
		size++;
	}

	void deleteElement() {
		auto newHead = head->next;
		delete head;
		head = newHead;
	}

	void print() {
		auto currentElement = head;
		while (currentElement != nullptr) {
			cout << currentElement->val << " ";
			currentElement = currentElement->next;
		}
		cout << endl;
	}

	int getSize() {
		return size;
	}

	~LinkedList() { // bitwise not
		auto currentElement = head;
		while (currentElement != nullptr) {
			auto toDelete = currentElement;
			currentElement = currentElement->next;
			delete toDelete;
		}
	}
};
// linear data structures: stack, queue, deque

void printLinkedList(ListNode *head) {
	ListNode *currentElement = head;
	while (currentElement != nullptr) {
		cout << currentElement->val << " ";
		currentElement = currentElement->next;
	}
	cout << endl;
}

void printLinkedListRec(ListNode *head) {
	if (head == nullptr) {
		cout << endl;
		return;
	}
	cout << head->val << " ";
	printLinkedListRec(head->next);
}

void deleteLinkedList(ListNode *head) {
	if (head == nullptr) {
		return;
	}
	deleteLinkedList(head->next);
	delete head;
}

void addNewElem(ListNode *head, int newVal) {
	ListNode *currentElement = head;
	while (currentElement->next != nullptr) {
		currentElement = currentElement->next;
	}
	ListNode *newNode = new ListNode();
	newNode->val = newVal;
	newNode->next = nullptr;
	currentElement->next = newNode;
}

void addNewElemRec(ListNode *head, int newVal) {
	if (head->next == nullptr) {
		ListNode *newNode = new ListNode();
		newNode->val = newVal;
		newNode->next = nullptr;
		head->next = newNode;
		return;
	}
	addNewElemRec(head->next, newVal);
}

int main() {
	LinkedList myList;
	for (int i = 1; i < 10000; i *= 2) {
		myList.addNewElement(i);
	}
	myList.print();

	for (int i = 0; i < 3; i++) {
		myList.deleteElement();
	}

	for (int i = 1; i < 10000; i *= 3) {
		myList.addNewElement(i);
	}
	myList.print();

	return 0;
}
//1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192
//1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 1 3 9 27 81 243 729 2187 6561
