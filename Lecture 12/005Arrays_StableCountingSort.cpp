// contraints : n <= 100, k <= 9

#include<iostream>

using namespace std;

// steps = 2n + 2k ~ O(n+k)
// space : O(k) due to freq[]

void countingSortStable(int arr[], int n, int k) {

	int freq[10] = {0}; // based on contraints

	for (int i = 0; i < n; i++) { // n-steps

		int x = arr[i];
		freq[x]++;

	}

	// for (int i = 0; i <= k; i++) {
	// 	cout << freq[i] << " ";
	// }

	// cout << endl;

	for (int i = 1; i <= k; i++) { // k-steps
		freq[i] = freq[i] + freq[i - 1];
	}

	// for (int i = 0; i <= k; i++) {
	// 	cout << freq[i] << " ";
	// }

	// cout << endl;

	for (int i = k; i >= 1; i--) { // k-steps
		freq[i] = freq[i - 1];
	}

	freq[0] = 0;

	// for (int i = 0; i <= k; i++) {
	// 	cout << freq[i] << " ";
	// }

	// cout << endl;

	int out[100]; // based on contraints

	for (int i = 0; i < n; i++) { // n-steps

		int x = arr[i];
		int idx = freq[x];
		out[idx] = x; // arr[i]
		freq[x]++;

		// out[freq[arr[i]]++] = arr[i];

	}

	for (int i = 0; i < n; i++) {
		cout << out[i] << " ";
	}

	cout << endl;


}

int main() {

	int arr[] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
	int n = sizeof(arr) / sizeof(int);

	int k = 3; // denotes the maximum element in the array

	countingSortStable(arr, n, k);

	return 0;
}