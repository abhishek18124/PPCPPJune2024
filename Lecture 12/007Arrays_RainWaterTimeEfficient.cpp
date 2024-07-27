// n <= 100

#include<iostream>

using namespace std;

// steps = 3n
// time : O(n) since each step is const
// space: 2n due to l[] and r[] ~ O(n)

int rainwaterOptimsied(int h[], int n) {

	int l[100]; // based on constraints
	l[0] = h[0];

	for (int i = 1; i < n; i++) {
		l[i] = max(l[i - 1], h[i]);
	}

	int r[100]; // based on contraints
	r[n - 1] = h[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;

	for (int i = 0; i < n; i++) {

		// find the water trapped on top of the ith building

		int wi = min(l[i], r[i]) - h[i];
		total += wi;

	}

	return total;

}

// steps = 2n
// time : O(n) since each step is const
// space: n due to r[] ~ O(n)

int rainwaterOptimsied2(int h[], int n) {


	int r[100]; // based on contraints
	r[n - 1] = h[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;
	int li = 0;

	for (int i = 0; i < n; i++) {

		// find the water trapped on top of the ith building

		li = max(li, h[i]);
		int wi = min(li, r[i]) - h[i];
		total += wi;

	}

	return total;

}

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	cout << rainwaterOptimsied(h, n) << endl;
	cout << rainwaterOptimsied2(h, n) << endl;

	return 0;
}