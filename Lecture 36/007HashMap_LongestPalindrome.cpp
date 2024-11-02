#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// time : O(n) assuming set ops. are const

int lengthOfLongestPalindrome(const string& str) {

	int cnt = 0; // to track the length of the longest palindrome we can form from str
	unordered_set<char> us;
	for (char ch : str) {
		if (us.find(ch) == us.end()) { // on avg. const
			us.insert(ch);
		} else {
			cnt += 2;
			us.erase(ch);
		}
	}

	if (us.size() > 0) cnt++;

	return cnt;

}

int main() {

	string str = "aaabbbbcc";

	cout << lengthOfLongestPalindrome(str) << endl;

	return 0;
}