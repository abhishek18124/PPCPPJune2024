#include<iostream>

using namespace std;

void inc(int& ref) {
	ref++;
}

int main() {

	int a = 0;

	cout << a << endl;

	inc(a);

	cout << a << endl;

	return 0;
}