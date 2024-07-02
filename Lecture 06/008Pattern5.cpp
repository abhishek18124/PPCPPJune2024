#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		// for the ith row, print n-i spaces

		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}

		// followed by i stars

		for (int j = 1; j <= i; j++) {
			cout << "*";
		}

		cout << endl;

	}

	cout << endl;

	int i = 1;
	while (i <= n) {

		// for the ith row, print n-i spaces

		int j = 1;

		while (j <= n - i) {

			cout << " ";
			j++;

		}

		// followed by i stars

		int k = 1;

		while (k <= i) {

			cout << "*";
			k++;

		}

		cout << endl;

		i++;

	}


	return 0;
}