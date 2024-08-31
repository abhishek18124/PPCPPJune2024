#include<iostream>

using namespace std;

// time : O(log(size of search space)) = O(logn)
// space: O(logn) due to fn call stack

// assume arr[] has duplicates
// hw 1 : find the 1st occ of t in sorted arr[]
// hw 2 : find the last occ of t in sorted arr[]

int f(int arr[], int t, int s, int e) {

	// base case

	if (s > e) {

		return -1; // search space is empty

	}

	// recursive case

	int m = s + (e - s) / 2;

	if (arr[m] == t) {

		return m;

	} else if (t > arr[m]) {

		// recursively, search for the t in arr[m+1...e]

		return f(arr, t, m + 1, e);

	} else {

		// recursively, search for the t in arr[s...m-1]

		return f(arr, t, s, m - 1);

	}

}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);
	int t = 100;

	cout <<	f(arr, t, 0, n - 1) << endl;

	return 0;
}