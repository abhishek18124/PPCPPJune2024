#include<iostream>
#include<vector>

using namespace std;

vector<int> ans;

void f(int X[], int n, int t, int i) {

	// base case

	if (i == n) {
		return; // mandatory
	}

	// recursive case

	if (X[i] == t) {
		ans.push_back(i);
	}

	f(X, n, t, i + 1);

	return; // optional

}

int main() {

	int X[] = {10, 20, 30, 10, 20};
	int n = sizeof(X) / sizeof(int);
	int t = 20;

	f(X, n, t, 0);

	if (ans.empty()) {
		cout << -1 << endl;
	} else {
		for (int x : ans) {
			cout << x << endl;
		}
	}

	return 0;
}