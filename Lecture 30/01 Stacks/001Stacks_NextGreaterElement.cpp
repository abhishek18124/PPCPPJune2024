#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

// time : e.g. [5, 4, 3, 2, 1] no. of push = n and no. of pop = n-1 therefore total operations = 2n-1 ~ O(n)
// space: e.g. [5, 4, 3, 2, 1] size of the stack doesn't exceed 1 ~ O(1)

// time : e.g. [1, 2, 3, 4, 5] no. of push = n and no. of pop = 0 therefore total operations = n ~ O(n)
// space: e.g. [1, 2, 3, 4, 5] size of the stack is equal to n ~ O(n)

// time : O(n)
// space: O(n)

vector<int> f(int A[], int n) {

	stack<int> s; // monotonic stack
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {

			// A[i] doesn't have any nearest greater element to its right

			ans.push_back(-1);

		} else {

			// s.top() is the nearest greater element to the right of A[i]

			ans.push_back(s.top());

		}

		s.push(A[i]);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	int A[] = {5, 3, 6, 7, 2, 1, 4};
	int n = sizeof(A) / sizeof(int);

	vector<int> ans = f(A, n);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}