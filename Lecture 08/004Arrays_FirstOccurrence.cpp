// n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[100]; // based on constraints

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int t;
	cin >> t;

	// in the worst case, we will run the loop n times i.e. we'll do n comparisions

	// time : n.const ~ O(n)

	int i;

	for (i = 0; i <= n - 1; i++) {

		if (arr[i] == t) { // const

			cout << t << " found at the index " << i << endl;
			break;

		}

	}

	if (i == n) {
		cout << -1 << endl;
	}

	return 0;
}