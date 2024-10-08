#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int t, const vector<int>& c, vector<int>& perm) {

	// base case

	if (t == 0) {

		for (int i = 0; i < perm.size(); i++) {
			cout << perm[i] << " ";
		}
		cout << endl;

		return;

	}

	// recursion case

	// generate permutations of 'c' that sums up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	for (int j = 0; j < c.size(); j++) {

		// check if c[j] can be the next element

		if (c[j] <= t) {

			// choose c[j] as the next element

			perm.push_back(c[j]);

			// t = t - c[j];
			// generatePermutations(t, c, perm);
			// t = t + c[j];

			generatePermutations(t - c[j], c, perm);

			perm.pop_back(); // backtracking

		}

	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> perm; // to track the permutation that sums up to 't'

	generatePermutations(t, c, perm);

	return 0;
}