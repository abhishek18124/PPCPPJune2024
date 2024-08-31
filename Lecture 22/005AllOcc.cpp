#include<iostream>

using namespace std;

bool flag = false; // assume t is not present in X[]

void f(int X[], int n, int t, int i) {

	// base case

	if (i == n) {
		if (flag == false) {
			cout << -1;
		}
		return; // mandatory
	}

	// recursive case

	if (X[i] == t) {
		cout << i << endl;
		flag = true;
	}

	f(X, n, t, i + 1);

	return; // optional

}

int main() {

	int X[] = {10, 20, 30, 10, 20};
	int n = sizeof(X) / sizeof(int);
	int t = 100;

	f(X, n, t, 0);

	return 0;
}