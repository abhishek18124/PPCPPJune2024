#include<iostream>
#include<string>

using namespace std;

// time : O(n)

int longestGoodSubstringOptimised(string str) {

	int maxSoFar = 0;
	int cnt = 0;

	for (char ch : str) {

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {

			// ch is a vowel

			cnt++;
			maxSoFar = max(maxSoFar, cnt);

		} else {

			// ch is a consonant

			cnt = 0;

		}

	}

	return maxSoFar;

}

int main() {

	string str = "cbaeicdeiou";

	cout << longestGoodSubstringOptimised(str) << endl;

	return 0;
}