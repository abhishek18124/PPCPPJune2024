#include<iostream>
#include<string>

using namespace std;

void generateSubstrings(string str, int n) {

	for (int i = 0; i < n; i++) {

		for (int j = i; j < n; j++) {

			// generate the substring that starts at the ith index and ends at the jth index

			// for (int k = i; k <= j; k++) {
			// 	cout << str[k];
			// }

			// cout << endl;

			cout << str.substr(i, j - i + 1) << endl;

		}

		cout << endl;

	}

}

int main() {

	string str = "abcde";
	int n = str.size();

	generateSubstrings(str, n);

	return 0;
}