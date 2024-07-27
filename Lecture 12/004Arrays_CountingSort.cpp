// contraints : n <= 100, k <= 9

#include<iostream>

using namespace std;

// steps = 2n
// time : O(n)
// space: k+1 due to freq[] ~ O(k)

void countingSort(int arr[], int n, int k) {

	int freq[10] = {0}; // based on contraints

	for (int i = 0; i < n; i++) { // n-steps

		int x = arr[i];
		freq[x]++;

		// freq[arr[i]]++;

	}

	// for (int i = 0; i <= k; i++) {
	// 	cout << "freq(" << i << ") = " << freq[i] << endl;
	// }

	for (int i = 0; i <= k; i++) { // n-steps

		int f = freq[i];

		// print 'i' f times

		for (int j = 1; j <= f; j++) {
			cout << i << " ";
		}


	}

}

int main() {

	int arr[] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
	int n = sizeof(arr) / sizeof(int);

	int k = 3; // denotes the maximum element in the array

	countingSort(arr, n, k);

	return 0;
}