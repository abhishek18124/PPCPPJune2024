#include<iostream>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool comparator(int a, int b) {

	if (a > b) {

		// we want to keep a before b since we are sorting in dec. order

		return true;

	}

	return false;

}

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// sorting a sequence in the decreasing order

	// 1. using a customer comparator

	sort(arr, arr + n, comparator); // [begin, end)

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// 2. using greater<T>() function object / functor

	int brr[] = {100, 50, 200, 150, 500, 0};
	int m = sizeof(brr) / sizeof(int);

	// sort(brr, brr + m, greater<int>());

	greater<int> v;
	sort(brr, brr + m, v);

	for (int i = 0; i < m; i++) {
		cout << brr[i] << " ";
	}

	cout << endl;



	return 0;
}
