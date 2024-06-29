#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 2;
	int rn = sqrt(n);
	while (i <= rn) {
		if (n % i == 0) {
			cout << n << " is not a prime number" << endl;
			break;
		}
		i = i + 1;
	}

	if (i > rn) {
		cout << n << " is a prime number" << endl;
	}

	return 0;
}