#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 1;

	while (i <= n) {

		// for the ith row, print i nos.

		int j = 1;

		// int num = i%2 == 0 ? 0 : 1;

		int num;

		if (i % 2 == 0) {
			// i is an even row
			num = 0;
		} else {
			// i is an odd row
			num = 1;
		}

		while (j <= i) {

			cout << num << " ";

			// if(num == 0) {
			// 	num = 1;
			// } else {
			// 	num = 0;
			// }

			// num = !num;

			num = 1 - num;

			j++;

		}

		cout << endl;

		i++;

	}

	return 0;
}