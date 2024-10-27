/*

	Given an array of n integers, sort the array using heap sort algorithm.

*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& v, int n, int i) {

	// fix the max heap prop. at index i

	int maxIdx = i;

	int leftChildIdx = 2 * i + 1;
	if (leftChildIdx < n and v[leftChildIdx] > v[maxIdx]) {
		maxIdx = leftChildIdx;
	}

	int rightChildIdx = 2 * i + 2;
	if (rightChildIdx < n and v[rightChildIdx] > v[maxIdx]) {
		maxIdx = rightChildIdx;
	}

	if (maxIdx != i) {
		swap(v[maxIdx], v[i]);
		heapify(v, n, maxIdx);
	}

}


int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	// time : n + nlogn ~ O(nlogn)
	// space: O(logn) due to fn call stk used during heapify
	// space can reduced to const if heapify is implemented iteratively (HW)

	// 1. transform v[] into a maxHeap - O(n)

	for (int i = n - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	// 2. tranform the maxHeap i.e. v[] into a sorted v[] - O(nlogn)

	int heapsize = n;
	while (heapsize > 1) {
		swap(v[0], v[heapsize - 1]);
		heapsize--;
		heapify(v, heapsize, 0);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
