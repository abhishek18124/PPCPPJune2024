#include<iostream>

using namespace std;

int main() {

	int arr[] = {1, 0, 1, 2, 0, 1, 2, 0, 1};
	int n = sizeof(arr) / sizeof(int);

	int low  = -1; // denotes the end   of the 0s region
	int mid  = 0;  // denotes the start of the unknown region
	int high = n;  // denotes the start of the 2s region

	/*

		arr[0.....low]  contains 0s
		arr[low+1...mid-1]  contains 1s
		arr[mid...high-1] contains unknown
		arr[high...n-1] contains 2s

	*/

	// time : O(n)
	// space: O(1)

	while (mid < high) {

		if (arr[mid] == 0) {

			// put arr[mid] in zeros

			low++;
			swap(arr[mid], arr[low]);
			mid++;

		} else if (arr[mid] == 1) {

			// put arr[mid] in ones

			mid++;

		} else {

			// put arr[mid] in twos

			high--;
			swap(arr[mid], arr[high]);

		}

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}