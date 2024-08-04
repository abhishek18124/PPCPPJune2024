#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdeabcde";

	cout << s.find("de") << endl;
	cout << s.rfind("de") << endl;
	cout << s.find("xyz") << endl;
	cout << string::npos << endl;

	return 0;
}