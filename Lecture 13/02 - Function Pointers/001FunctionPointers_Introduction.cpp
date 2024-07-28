#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	void (*gptr)() = &greet;
	int (*aptr)(int , int) = &add;
	bool (*ascptr)(int, int) = &ascending;

	cout << (void*)&greet << endl;
	cout << (void*)greet << endl;
	cout << (void*)gptr << endl << endl;

	cout << (void*)&add << endl;
	cout << (void*)add << endl;
	cout << (void*)aptr << endl << endl;

	cout << (void*)&ascending << endl;
	cout << (void*)ascending << endl;
	cout << (void*)ascptr << endl;


	(*gptr)();
	gptr();
	greet();
	(*greet)();

	cout << (*aptr)(2, 3) << endl;
	cout << aptr(2, 3) << endl;
	cout << add(2, 3) << endl;
	cout << (*add)(2, 3) << endl;

	return 0;
}