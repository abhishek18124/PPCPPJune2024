#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "hello";

	reverse(s.begin(), s.end());

	cout << s << endl;

	string s2 = "abcdef";

	reverse(s2.begin() + 1, s2.begin() + 5); // [1, 5)

	cout << s2 << endl;


	return 0;
}