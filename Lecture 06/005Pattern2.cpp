#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// int i = 1;

	// while (i <= n) {

	// 	// for the ith row, print i nos.

	// 	int j = 1;

	// 	while (j <= i) {

	// 		cout << j << " ";
	// 		j++;

	// 	}

	// 	cout << endl;

	// 	i++;

	// }

	int i = 1;

	while (i <= n) {

		// for the ith row, print i nos. in the inc. order starting with 1

		int j = 1;
		int num = 1;

		while (j <= i) {
			cout << num << " ";
			num++;
			j++;

		}

		cout << endl;

		i++;

	}

	return 0;
}