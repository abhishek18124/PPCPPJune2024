#include<iostream>

using namespace std;

int main() {

	int arr[] = {2, 3, 2, 4, 0, 2, 0};
	int n = sizeof(arr) / sizeof(int);
	int k = 6;

	// time : O(n)
	// space: O(1)

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the window

	int w_sum = 0; // to store the window sum

	int max_len = 0; // to track the length of the longest
	// window which has a sum equals to k

	while (j < n) {

		// expand the window
		w_sum += arr[j];

		// check for the violation of the window property
		if (w_sum > k) {
			// window property is violated, start shrinking
			while (w_sum > k) {
				w_sum -= arr[i];
				i++;
			}
		}

		// check for the validity of the window, and update the answer
		if (w_sum == k) {
			// you've found a valid window
			max_len = max(max_len, j - i + 1); // j-i+1 is the len of the current valid window
		}

		// continue expansion of the window
		j++;

	}

	cout << max_len << endl;

	return 0;
}