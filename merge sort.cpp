#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int l, int mid, int r) {
	int size = r - l + 1;
	vector<int> temporaryVec(size);
	for (int i = l, j = mid, k = 0; k < size; k++) {
		if (i == mid) {
			temporaryVec[k] = nums[j];
			j++;
		} else if (j > r) {
			temporaryVec[k] = nums[i];
			i++;
		} else {
			if (nums[i] < nums[j]) {
				temporaryVec[k] = nums[i];
				i++;
			} else {
				temporaryVec[k] = nums[j];
				j++;
			}
		}
	}
	for (int i = l, k = 0; k < size; i++, k++) {
		nums[i] = temporaryVec[k];
	}
}

void mergeSort(vector<int> &nums, int l, int r) {
	if (l >= r) {
		return;
	}
	if (l + 1 == r) {
		if (nums[l] > nums[r]) {
			swap(nums[l], nums[r]);
		}
		return;
	}
	int mid = (l + r) / 2;
	mergeSort(nums, l, mid);
	mergeSort(nums, mid + 1, r);
	merge(nums, l, mid + 1, r);
}

void printVector(vector<int> &vec) {
	for (int elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}

int main() {
	int arraySize = 1000;
	vector<int> nums;
	for (int i = 0; i < arraySize; i++) {
		nums.push_back(rand());
	}
	vector<int> nums2 = nums;
	int n = nums.size();
	mergeSort(nums, 0, n - 1);
	printVector(nums);
	cout << "\n\n\n\n" << endl;
	sort(nums2.begin(), nums2.end());
	printVector(nums2);
	return 0;
}
