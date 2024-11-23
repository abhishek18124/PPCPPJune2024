#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int f(const vector<int>& arr, int n, int k, int i) {

	// base case

	if (i == n) {
		// you've built a valid partition
		return 0;
	}

	// recursive case

	// f(i) = it is a fn to find the maximum sum from partitioning arr[i...n-1]

	// decide the next cut

	int maxij = INT_MIN;
	int maxSoFar = INT_MIN;

	for (int j = i; j < i + k and j < n; j++) {

		maxij = max(maxij, arr[j]);

		// make a cut at index j

		// we'll get a subarray from i to j

		// sum(arr[i...j]) = max(arr[i...j]) * length

		maxSoFar = max(maxSoFar, maxij * (j - i + 1) + f(arr, n, k, j + 1));

	}

	return maxSoFar;

}
// time : O(nk)
// space: O(n) due to dp[], can be optimised to O(k) since dp[i] depends on next k cells

int fBottomUp(const vector<int>& arr, int n, int k) {

	vector<int> dp(n + 1);
	dp[n] = 0; // at the nth index of dp[] we store f(n)
	for (int i = n - 1; i >= 0; i--) {
		// dp[i] = f(i)
		// f(i) = it is a fn to find the maximum sum from partitioning arr[i...n-1]

		// decide the next cut

		int maxij = INT_MIN;
		int maxSoFar = INT_MIN;

		for (int j = i; j < i + k and j < n; j++) {

			maxij = max(maxij, arr[j]);

			// make a cut at index j

			// we'll get a subarray from i to j

			// sum(arr[i...j]) = max(arr[i...j]) * length

			maxSoFar = max(maxSoFar, maxij * (j - i + 1) + dp[j + 1]);

		}

		dp[i] = maxSoFar;
	}
	return dp[0]; // at the 0th index of dp[] we store f(0)

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {

	int n = arr.size();

	// return f(arr, n, k, 0);

	return fBottomUp(arr, n, k);
}

int main() {

	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;

	cout << maxSumAfterPartitioning(arr, k) << endl;

	return 0;
}