#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 4;

	int mask = 1 << k;

	if ((n & mask) == 0) {

		cout << "bit " << k << " of " << n << " is not set" << endl;

	} else {

		cout << "bit " << k << " of " << n << " is set" << endl;

	}

	if (n & mask) {

		cout << "bit " << k << " of " << n << " is set" << endl;

	} else {

		cout << "bit " << k << " of " << n << " is not set" << endl;

	}

	if (((n >> k) & 1) == 0) {

		cout << "bit " << k << " of " << n << " is not set" << endl;

	} else {

		cout << "bit " << k << " of " << n << " is set" << endl;

	}

	if ((n >> k) & 1) {

		cout << "bit " << k << " of " << n << " is set" << endl;

	} else {

		cout << "bit " << k << " of " << n << " is not set" << endl;

	}

	return 0;
}