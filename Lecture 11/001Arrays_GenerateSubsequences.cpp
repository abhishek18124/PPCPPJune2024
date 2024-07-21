#include<iostream>

using namespace std;

void generateSubsequences(int arr[], int n) {

	for (int num = 0; num < (1 << n); num++) {

		// generate the subsequence corresponding to num

		cout << num << " : ";

		for (int k = 0; k < n; k++) {

			// check if the kth bit of num is set

			if ((num >> k) & 1) {
				cout << arr[k] << " ";
			}

		}

		cout << endl;

	}

}

int main() {

	int arr[] = {10, 20, 30, 40};
	int n = sizeof(arr) / sizeof(int);

	generateSubsequences(arr, n);

	return 0;
}
