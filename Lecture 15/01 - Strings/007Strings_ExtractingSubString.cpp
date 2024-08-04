#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdef";
	cout << s.substr(2) << endl;
	cout << s.substr(2, 3) << endl;

	return 0;
}