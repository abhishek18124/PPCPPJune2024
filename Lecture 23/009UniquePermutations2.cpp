/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>

using namespace std;

void f(char inp[], int n, int i) {

	// base case

	if (i == n) { // inp[i] == '\0'
		cout << inp << endl;
		return;
	}

	// recursive case

	// decide for the ith position

	for (int j = i; j < n; j++) {

		// can you choose the jth option ?

		bool flag = true; // assume you can choose the jth option

		for (int k = j + 1; k < n; k++) {
			if (inp[k] == inp[j]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			// choose the jth option for the ith position
			swap(inp[i], inp[j]);
			f(inp, n, i + 1);
			swap(inp[i], inp[j]); // backtracking
		}

	}

}

int main() {

	char inp[] = "aabc";
	int n = strlen(inp);

	f(inp, n, 0);

	return 0;
}
