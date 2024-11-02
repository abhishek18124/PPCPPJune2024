#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool isDuplicatePresent(const vector<int>& v) {

	unordered_map<int, int> freqMap;

	for (int i = 0; i < v.size(); i++) { // n.const ~ O(n)

		int x = v[i];
		freqMap[x]++; // on. avg. const
		if (freqMap[x] > 1) {
			// you've found a duplicate
			return true;
		}

	}

	// for (pair<int, int> p : freqMap) {
	// 	cout << "freq(" << p.first << ") = " << p.second << endl;
	// }

	return false;

}

bool isDuplicatePresent2(const vector<int>& v) {

	unordered_set<int> us;

	for (int i = 0; i < v.size(); i++) {

		int x = v[i];
		if (us.find(x) == us.end()) {
			us.insert(x);
		} else {
			// us.find(x) != us.end()
			// x was seen previously, therefore you've found a duplicate
			return true;
		}

	}

	// no duplicates were found
	return false;
}

int main() {

	vector<int> v = {1, 2, 3, 1, 4};

	isDuplicatePresent(v) ? cout << "true" << endl :
	                             cout << "false" << endl;


	isDuplicatePresent2(v) ? cout << "true" << endl :
	                              cout << "false" << endl;



	return 0;
}