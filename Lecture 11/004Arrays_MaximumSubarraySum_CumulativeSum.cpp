// constraints : n <= 100

#include<iostream>
#include<climits>

using namespace std;

// time : n + n^2 ~ O(n^2)
// space: n + 1 ~ O(n)

int maximumSubarraySumOptimised(int arr[], int n) {

	int csum[101];
	csum[0] = 0;

	for (int i = 1; i <= n; i++) {
		csum[i] = csum[i - 1] + arr[i - 1];
	}

	int maxSoFar = INT_MIN;

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			// compute the sum of the subarray that starts at the ith index and ends at the jth index

			int sum = csum[j + 1] - csum[i];
			maxSoFar = max(maxSoFar, sum);

		}

	}

	return maxSoFar;

}

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySumOptimised(arr, n) << endl;

	return 0;
}