/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>
#include<set>

using namespace std;

set<string> s;

void f(char inp[], int n, int i) {

	// base case

	if (i == n) { // inp[i] == '\0'
		// cout << inp << endl;

		// string obj(inp);
		// s.insert(obj);

		s.insert(string(inp));

		return;
	}

	// recursive case

	// decide for the ith position

	for (int j = i; j < n; j++) {

		// choose the jth option for the ith position
		swap(inp[i], inp[j]);
		f(inp, n, i + 1);
		swap(inp[i], inp[j]); // backtracking

	}

}

int main() {

	char inp[] = "aabc";
	int n = strlen(inp);

	f(inp, n, 0);

	for (string permutation : s) {
		cout << permutation << endl;
	}

	return 0;
}
