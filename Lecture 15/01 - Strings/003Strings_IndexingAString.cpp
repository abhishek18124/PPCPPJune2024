#include<iostream>
#include<string>

using namespace std;

int main() {

	string str3 = "coding";

	// cout << str3[0] << endl;
	// cout << str3[1] << endl;
	// cout << str3[2] << endl;
	// cout << str3[3] << endl;
	// cout << str3[4] << endl;
	// cout << str3[5] << endl;

	for (int i = 0; str3[i] != '\0'; i++) {
		cout << str3[i] << endl;
	}

	cout << endl;

	string str4 = "india";

	cout << str4.size() << endl;
	cout << str4.length() << endl;

	for (int i = 0; i < str4.size(); i++) {
		cout << str4[i] << endl;
	}

	return 0;
}