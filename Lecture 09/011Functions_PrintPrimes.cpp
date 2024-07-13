#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {

	int rn = sqrt(n);
	for (int i = 2; i <= rn; i++) {
		if (n % i == 0) {
			// you've found a factor of n in the range [2, rn]
			return false;
		}
	}

	// n has no factors in the range [2, rn]
	return true;

}

// adv. of using fn

// modularity
// readability
// reusability

void printPrimes(int m) {

	for (int n = 2; n <= m; n++) {

		// check if n is prime

		if (isPrime(n)) {

			cout << n << endl;

		}

	}

}

int main() {

	int m;
	cin >> m;

	printPrimes(m);

	return 0;
}