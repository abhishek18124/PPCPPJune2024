#include<iostream>

using namespace std;

bool isEven(int n) {

	return n % 2 == 0;

}

int main() {

	bool ans = isEven(5); // when a fn returns a value you can treat the fn call as an expr

	if (ans == true) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	cout << isEven(4) << endl;

	if (isEven(8)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	isEven(9) ? cout << "even" << endl : cout << "odd" << endl;

	return 0;
}