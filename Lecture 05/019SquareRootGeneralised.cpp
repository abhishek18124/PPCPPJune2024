#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int p;
	cin >> p;

	cout << sqrt(n) << endl;

	double ans = 0;

	while (ans * ans <= n) {
		ans = ans + 1;
	}

	ans = ans - 1;

	int i = 1;
	double inc = 0.1;

	while (i <= p) {

		while (ans * ans <= n) {
			ans = ans + inc;
		}
		ans = ans - inc;
		inc = inc / 10;

		i = i + 1;
	}

	cout << ans << endl;

	return 0;
}