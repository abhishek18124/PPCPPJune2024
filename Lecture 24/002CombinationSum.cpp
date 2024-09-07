#include<iostream>
#include<vector>

using namespace std;

void generateCombinations(int t, const vector<int>& c, vector<int>& comb, int i) {

	// base case

	if (t == 0) {

		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << " ";
		}

		cout << endl;
		return;

	}

	// recursion case

	// generate the combinations of c[i...n-1] that sum up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	for (int j = i; j < c.size(); j++) {

		// can you choose c[j] as the next element of comb[]

		if (c[j] <= t) {

			// you can choose c[j] as the next element

			comb.push_back(c[j]);
			generateCombinations(t - c[j], c, comb, j); // use this call to make sure an element can be used any no. of times
			// generateCombinations(t - c[j], c, comb, j+1); // use this call to make sure each element is used only once
			comb.pop_back(); // backtracking

		}

	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> comb; // to track the combination that sums up to 't'

	generateCombinations(t, c, comb, 0);

	return 0;
}