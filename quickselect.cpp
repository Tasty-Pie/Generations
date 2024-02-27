#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int partition(vector<int> &nums, int l, int r) {
	int pivotIndex = l + (rand() % (r - l + 1));
	int pivot = nums[pivotIndex];
	swap(nums[r], nums[pivotIndex]);
	int i = l; // i - destination index
	for (int j = l; j < r; j++) {
		if (nums[j] < pivot) {
			swap(nums[i], nums[j]);
			i++;
		}
	}
	swap(nums[i], nums[r]);
	return i;
}

int quickSelect(vector<int> &nums, int k) {
	int l = 0, r = nums.size() - 1;
	while (l < r) {
		int pivotIndex = partition(nums, l, r);
		if (pivotIndex == k) {
			return nums[k];
		} else if (pivotIndex < k) {
			l = pivotIndex + 1;
		} else {
			r = pivotIndex - 1;
		}
	}
	return nums[l];
}

int main() {
	srand(time(0));
	int numsSize = 100000;
	cout << "Size = " << numsSize << ":\n";

	long quickSelectCount = 0;
	long nth_elementCount = 0;
	long sortingCount = 0;
	for (int j = 0; j < 10000; j++) {
		vector<int> nums;
		for (int i = 0; i < numsSize; i++) {
			nums.push_back(rand());
		}
		int n = rand() % numsSize;
		auto numsCopy = nums;
		auto numsCopy1 = nums;

		auto start = high_resolution_clock::now();
		quickSelect(nums, n);
		auto stop = high_resolution_clock::now();
		quickSelectCount += (duration_cast<milliseconds>(stop - start)).count();
		int nthNum = nums[n];

		start = high_resolution_clock::now();
		nth_element(numsCopy.begin(), numsCopy.begin() + n, numsCopy.end());
		stop = high_resolution_clock::now();
		nth_elementCount += (duration_cast<milliseconds>(stop - start)).count();
		if (nthNum != numsCopy[n]) {
			throw runtime_error("err");
		}
		nthNum = numsCopy[n];

		start = high_resolution_clock::now();
		sort(numsCopy1.begin(), numsCopy1.end());
		stop = high_resolution_clock::now();
		sortingCount += (duration_cast<milliseconds>(stop - start)).count();

		if (nthNum != numsCopy[n]) {
			throw runtime_error("err");
		}
	}

	cout << "Quick Select Time: " << quickSelectCount << " ms\n";

	cout << "nth_element Time: " << nth_elementCount << " ms\n";

	cout << "Sorting Time: " << sortingCount << " ms\n";

	cout << "Finished!!!" << endl;
	return 0;
}
