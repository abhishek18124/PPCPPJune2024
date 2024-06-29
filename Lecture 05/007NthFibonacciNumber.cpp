#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 || n == 1) {

		cout << n << endl; // since 0th fib. no. is 0 and 1st fib. no. is 1

	} else {

		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.

		int i = 2;

		while (i <= n) {

			int c = a + b;
			a = b;
			b = c;

			i = i + 1;

		}

		cout << b << endl;


	}

	return 0;
}