#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s1 = "taste";

	sort(s1.begin(), s1.end());

	cout << s1 << endl;

	string s2 = "state";

	sort(s2.begin(), s2.end());

	cout << s2 << endl;

	return 0;
}