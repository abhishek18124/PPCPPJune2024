#include<iostream>

using namespace std;

int main() {

	int a = 5;
	int b = 3;

	a *= b - 1; // a = a * b - 1 // a = 5 * 3 - 1 // a = 15 - 1 = 14 // incorrect

	// a = a * (b-1) = 5 * (3-1) = 5 * 2 = 10 // correct

	cout << a << endl;

	return 0;
}