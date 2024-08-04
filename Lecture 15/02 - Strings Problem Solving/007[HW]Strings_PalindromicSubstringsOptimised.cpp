#include<iostream>
#include<string>

using namespace std;

int countPalindromicSubstringsOptimised(string s) {

	int cnt = 0; // to track the no. of palindromic substrings in the given string

	// 1. count odd-length palindromic substrings in s

	int n = s.size();

	for (int i = 0; i < n; i++) {

		// find no. of odd-length palindromic substrings around s[i]

		int j = 0;

		while (i + j < n and i - j >= 0 and s[i + j] == s[i - j]) {
			cnt++;
			j++;
		}

		cout << "odd-length palindromic substrings around s[" << i << "] = " << j << endl;

	}

	// 2. count even-length palindromic substrings in s

	for (double i = 0.5; i < n; i++) {

		// find no. of even-length palindromic substrings around ith center

		double j = 0.5;
		int localCnt = 0;

		while (i + j < n and i - j >= 0 and s[int(i + j)] == s[int(i - j)]) {
			cnt++;
			j++;
			localCnt++;
		}

		cout << "even-length palindromic substrings around " << i << " = " << localCnt << endl;


	}

	return cnt;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstringsOptimised(s) << endl;

	return 0;
}