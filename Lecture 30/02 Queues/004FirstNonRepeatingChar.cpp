#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<char> q;
	int freqMap[26] = {0};

	char ch;

	while (true) {

		cin >> ch;

		if (ch == '.') break;

		freqMap[ch - 'a']++;
		if (freqMap[ch - 'a'] == 1) {
			q.push(ch);
		}

		// find the 1st non-repeating character in the stream for ch

		while (!q.empty() and freqMap[q.front() - 'a'] > 1) {
			// character at the front of the queue is repeating so it is of no use
			q.pop();
		}

		if (q.empty()) {
			// there are no non-repeating characters in the stream
			cout << -1 << " ";
		} else {
			cout << q.front() << " ";
		}

	}

	return 0;
}