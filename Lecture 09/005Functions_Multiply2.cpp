#include<iostream>

using namespace std;

int multiply(int a, int b) { // args. are passed by value

	int c = a * b;
	return c; // c is returned by value

}

int main() {

	int a = 3;
	int b = 4;

	cout << multiply(a, b) << endl;

	return 0;
}