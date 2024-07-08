#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 10;

	int cnt = 0; // to track the no. of occ. of t in arr[]
	bool flag = false; // assume t is not present in arr[]

	for (int i = 0; i <= n - 1; i++) {

		if (arr[i] == t) {
			flag = true;
			cnt++;
			cout << i << " ";

		}

	}

	if (flag == false) {
		cout << -1 << endl;
	}

	if (cnt == 0 ) {

		cout << -1 << endl;

	}

	return 0;
}