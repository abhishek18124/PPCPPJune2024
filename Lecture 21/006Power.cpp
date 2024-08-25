#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {
		// find x^0
		return 1;
	}

	// recursive case

	// f(x, y) = find x^y or multiplies x, y times

	// 1. ask your friend to find x^y-1 or ask your friend to multiply x, y-1 times

	int A = f(x, y - 1);

	return x * A;

}

int main() {

	int x = 3;
	int y = 4;

	cout << f(x, y) << endl;

	return 0;
}