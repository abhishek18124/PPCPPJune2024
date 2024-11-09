/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

	// time : O(n)

	int longestConsecutive(vector<int>& nums) {

		unordered_map<int, bool> startMap;

		for (int i = 0; i < nums.size(); i++) { // on avg. linear time

			if (startMap.find(nums[i] - 1) == startMap.end()) {
				// nums[i] - 1 is not present
				startMap[nums[i]] = true;
			} else {
				// nums[i] - 1 is present
				startMap[nums[i]] = false;
			}

			if (startMap.find(nums[i] + 1) != startMap.end()) {
				// nums[i] + 1 is present
				startMap[nums[i] + 1] = false;
			}


		}

		// for (pair<int, bool> p : startMap) {
		// 	cout << p.first << " " << p.second << endl;
		// }

		int maxSoFar = 0; // or INT_MIN

		for (pair<int, bool> p : startMap) { // on avg. linear
			int el = p.first;
			bool canStart = p.second;
			if (canStart) {
				// find the length of the sequence of consecutive elements
				//  that starts from 'el'
				int key = el;
				int cnt = 0;
				while (startMap.find(key) != startMap.end()) {
					cnt++;
					key++;
				}
				// cout << "starting = " << el << " length = " << cnt << endl;
				maxSoFar = max(maxSoFar, cnt);
			}
		}

		return maxSoFar;

	}
};

int main() {

	Solution s;

	vector<int> nums = {3, 5, 2, 7, 1, 6, 10, 12, 9, 8, 13};

	cout << s.longestConsecutive(nums) << endl;

}
