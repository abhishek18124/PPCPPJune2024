/*

Suppose there is a ladder with n steps. A person standing at the bottom of the ladder and wants to
reach to its top. Assume the person can take atmost k steps at a time. Then, count the number
of ways, the person can reach the top of the ladder.

Example
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1],
	              [1, 1, 2],
	              [1, 2, 1],
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/
#include<iostream>
#include<vector>

using namespace std;

vector<int> path;

int f1(int n, int k, int i) {

	// base case

	if (i == n) {

		// f(n) = count no. of ways to go from n to n

		// you've reached the destn through a path

		for (int& x : path) {
			cout << x << " ";
		}
		cout << endl;

		return 1;

	}

	// recursive case

	// f(i) = count no. of ways to go from i to n

	// decide the size of the next step / jump

	int cnt = 0;

	for (int j = 1; j <= k; j++) {

		// can I take a jump of size j from the ith step

		if (i + j <= n) {

			// you can take a jump of size j

			// ask your friend to count no. of ways to go from i+j to n

			path.push_back(j);
			cnt += f1(n, k, i + j);
			path.pop_back(); // backtracking

		}

	}

	return cnt;

}

int f2(int n, int k, int i) {

	// base case

	if (i == n) {

		// f(n) = count no. of ways to go from n to n

		// you've reached the destn through a path

		return 1;

	}

	if (i > n) {

		return 0;
	}

	// recursive case

	// f(i) = count no. of ways to go from i to n

	// decide the size of the next step / jump

	int cnt = 0;

	for (int j = 1; j <= k; j++) {

		// you can take a jump of size j

		// ask your friend to count no. of ways to go from i+j to n

		cnt += f2(n, k, i + j);

	}

	return cnt;

}

int main() {

	int n = 4;
	int k = 3;

	// cout << f(n, k, 0) << endl;

	cout << f2(n, k, 0) << endl;

	return 0;
}