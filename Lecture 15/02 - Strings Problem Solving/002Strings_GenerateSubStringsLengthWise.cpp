#include<iostream>
#include<string>

using namespace std;

void generateSubstringsLengthwise(string str, int n) {

	for (int l = 1; l <= n; l++) {

		// generate all the substrings of length l

		for (int i = 0; i <= n - l; i++) {

			cout << str.substr(i, l) << endl;

		}

		cout << endl;

	}

}

int main() {

	string str = "abcde";
	int n = str.size();

	generateSubstringsLengthwise(str, n);

	return 0;
}