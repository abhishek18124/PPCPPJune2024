#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 2;
	while (i <= n - 1) {
		if (n % i == 0) {
			cout << n << " is not a prime number" << endl;
			break;
		}
		i = i + 1;
	}

	if (i == n) {
		cout << n << " is a prime number" << endl;
	}

	return 0;
}