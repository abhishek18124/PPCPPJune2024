#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	string s2 = "def";

	s1.append(s2);

	cout << s1 << endl;
	cout << s2 << endl;

	string s3 = "uvw";
	string s4 = "xyz";

	s3 = s3 + s4;

	cout << s3 << endl;
	cout << s4 << endl;

	return 0;
}