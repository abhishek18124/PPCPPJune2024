#include<iostream>

using namespace std;

int main() {

	char ch = 'A';

	cout << ch << endl;
	cout << (int)ch << endl;

	ch = 'c';
	cout << ch << endl;
	cout << (int)ch << endl;

	ch = '7';
	cout << ch << endl;
	cout << (int)ch << endl;

	char ch2 = 100;
	cout << ch2 << endl;

	int x = 'A';
	cout << x << endl;

	char ch3 = '5';
	int d3 = ch3 - '0';
	cout << d3 << endl;

	return 0;
}