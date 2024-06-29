#include<iostream>

using namespace std;

int main() {

	int x = 10;

	cout << x << endl;

	{
		int y = 20;

		cout << x << " " << y << endl;

	}

	cout << x << endl;
	// cout << y << endl; // error : y is not in scope

	return 0;
}