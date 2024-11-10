#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "aabacbebebe";
	int n = s.size();
	int k = 3;

	// time : O(n)
	// space: O(size of map)

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the windw

	int max_len = 0; // to track the length of the longest substring
	// i.e. window that contain k unique characters

	int uniqCnt = 0; // to keep track of no. of unique characters in the window

	unordered_map<char, int> freqMap; // to store a  mapping  between characters
	// present in a window & their frequencies

	while (j < n) {

		// expand the window
		freqMap[s[j]]++;
		if (freqMap[s[j]] == 1) {
			uniqCnt++;
		}

		// check for the violation of the window property
		if (uniqCnt > k) {
			// window property is violated, start shrinking
			while (uniqCnt > k) {
				freqMap[s[i]]--;
				if (freqMap[s[i]] == 0) {
					uniqCnt--;
				}
				i++;
			}
		}

		// check for the validity of the window, and update the answer
		if (uniqCnt == k) {
			// you've found a valid window
			max_len = max(max_len, j - i + 1); // j-i+1 is the length of the current valid window
		}

		// continue expansion of the window

		j++;
	}

	cout << max_len << endl;

	return 0;
}