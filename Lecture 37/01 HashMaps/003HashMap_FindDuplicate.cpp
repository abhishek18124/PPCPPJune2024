#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> v = {2, 5, 3, 5, 1, 4, 6};

	int slow = v[0];
	int fast = v[0];

	while (true) {

		slow = v[slow];
		fast = v[v[fast]];

		if (slow == fast) {
			break;
		}

	}

	slow = v[0];

	while (slow != fast) {
		slow = v[slow];
		fast = v[fast];
	}

	cout << slow << endl; // cout << fast << endl;

	return 0;
}