#include<iostream>

using namespace std;

int stringToInteger(string str, int n) {

	// base case

	if (n == 0) {
		return 0;
	}

	// if (n == 1) {
	// 	return str[0] - '0';
	// }

	// recursive case

	// f(str, n) = convert the given string str of length n into an integer

	string subString = str.substr(0, n - 1);
	int ansFromMyFriend = stringToInteger(subString, n - 1);
	return ansFromMyFriend * 10 + (str[n - 1] - '0');

}

int main() {

	string str = "12345";
	int n = str.size();

	int ans = stringToInteger(str, n);

	cout << ans << endl;

	return 0;
}