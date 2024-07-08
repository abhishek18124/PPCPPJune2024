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

	int i;

	for (i = n - 1; i >= 0; i--) {

		if (arr[i] == t) {

			cout << t << " found at index " << i << endl;
			break;

		}

	}

	if (i == -1) {
		cout << -1 << endl;
	}

	return 0;
}