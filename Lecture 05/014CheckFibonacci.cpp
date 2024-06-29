#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 || n == 1) {

		// n is part of fib. sequence

		cout <<  "true" << endl;

	} else {

		// generate fib. no.

		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.

		while (true) {
			int c = a + b;

			cout << c << " ";

			if (c == n) {
				// n is part of fib. sequence
				cout << "true" << endl;
				break;
			}

			if (c > n) {
				// n is not part of fib. seq.
				cout << "false" << endl;
				break;
			}

			// c < n

			a = b;
			b = c;
		}

	}

	return 0;
}