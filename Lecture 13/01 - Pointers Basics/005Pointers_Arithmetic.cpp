#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int* xptr = &x;

	cout << "xptr = " << xptr << endl;

	xptr = xptr + 1;

	cout << "xptr = " << xptr << endl;

	int* yptr = &x;

	cout << "yptr = " << yptr << endl;

	yptr = yptr + 2;

	cout << "yptr = " << yptr << endl;

	return 0;
}