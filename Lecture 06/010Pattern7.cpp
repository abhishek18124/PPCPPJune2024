#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 1;

	while (i <= n) {

		// for the ith row, print n-i spaces

		int j = 1;

		while (j <= n - i) {
			cout << "  ";
			j++;
		}

		// followed by i nos. in the inc. order starting with i

		int num = i;
		j = 1;

		while (j <= i) {
			cout << num << " ";
			num++;
			j++;
		}

		// followed by i-1 nos. in the dec. order starting with 2i-2

		// num = 2 * i - 2;
		num = num - 2;
		j = 1;

		while (j <= i - 1) {
			cout << num << " ";
			num--;
			j++;
		}

		cout << endl;

		i++;

	}

	return 0;
}