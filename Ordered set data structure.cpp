#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() :
			val(0), left(nullptr), right(nullptr) {
	}
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
	TreeNode(int x, TreeNode *left, TreeNode *right) :
			val(x), left(left), right(right) {
	}
};

class OrderedSet {
private:
	TreeNode *root;
	int size;

	void destructor(TreeNode *node) {
		if (node == nullptr) {
			return;
		}
		destructor(node->left);
		destructor(node->right);
		delete node;
	}

	void printHelper(TreeNode *node) {
		if (node == nullptr) {
			return;
		}
		printHelper(node->left);
		cout << node->val << " ";
		printHelper(node->right);
	}

public:
	OrderedSet() :
			root(nullptr), size(0) {
	}

	bool insertValue(int newValue) {
		if (root == nullptr) {
			root = new TreeNode(newValue);
			size = 1;
			return true;
		}
		TreeNode *previousNode = nullptr;
		TreeNode *currentNode = root;
		while (currentNode != nullptr) {
			previousNode = currentNode;
			if (currentNode->val == newValue) {
				return false;
			} else if (currentNode->val < newValue) {
				currentNode = currentNode->right;
			} else {
				currentNode = currentNode->left;
			}
		}
		if (previousNode->val < newValue) {
			previousNode->right = new TreeNode(newValue);
		} else {
			previousNode->left = new TreeNode(newValue);
		}
		size++;
		return true;
	}

//	bool deleteValue(int targetValue) {
//
//	}

	bool containsValue(int targetValue) {
		TreeNode *currentNode = root;
		while (currentNode != nullptr) {
			if (currentNode->val == targetValue) {
				return true;
			} else if (currentNode->val < targetValue) {
				currentNode = currentNode->right;
			} else {
				currentNode = currentNode->left;
			}
		}
		return false;
	}

	void clear() {
		destructor(root);
		size = 0;
	}

	int getSize() {
		return size;
	}

	void print() {
		printHelper(root);
		cout << endl;
	}

	~OrderedSet() {
		destructor(root);
	}
};

int main() {
	OrderedSet mySet;

	mySet.insertValue(0);
	mySet.insertValue(1);
	mySet.insertValue(10);
	mySet.insertValue(2);
	mySet.print();

	mySet.insertValue(2);
	mySet.insertValue(2);
	mySet.insertValue(10);
	mySet.print();

	if (mySet.containsValue(2)) {
		cout << "contains 2" << endl;
	}
	if (mySet.containsValue(3)) {
		cout << "contains 3" << endl;
	}
	if (mySet.containsValue(4)) {
		cout << "contains 4" << endl;
	}
	if (mySet.containsValue(10)) {
		cout << "contains 10" << endl;
	}
	return 0;
}
