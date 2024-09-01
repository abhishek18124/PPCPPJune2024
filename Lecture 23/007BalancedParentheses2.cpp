// n <= 8

#include<iostream>

using namespace std;

void f(int n, char out[], int i, int oc, int cc) {

	// base case

	if (i == 2 * n) { // oc == n and cc == n
		out[i] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// decide for ith position of out[]

	// option 1 : use '('

	if (oc < n) {
		out[i] = '(';
		oc++;
		f(n, out, i + 1, oc, cc);
		oc--; // backtracking
	}

	// option 2 : use ')'

	if (cc < oc) {
		out[i] = ')';
		cc++;
		f(n, out, i + 1, oc, cc);
		cc--; // backtracking
	}

}

int main() {

	int n = 3;

	char out[17]; // based on constraints

	f(n, out, 0, 0, 0);

	return 0;
}