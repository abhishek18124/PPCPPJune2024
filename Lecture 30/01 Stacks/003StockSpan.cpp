#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// vector<int> f(int A[], int n) {

// 	vector<int> ans;
// 	stack<pair<int, int>> s; // monotonic stack (index, element)

// 	for (int i = 0; i < n; i++) {

// 		// to find the span for the ith day, find out what the index of the nearest greater element to the left of A[i]

// 		while (!s.empty() and s.top().second <= A[i]) {
// 			s.pop();
// 		}

// 		int j;

// 		if (s.empty()) {
// 			j = -1;
// 		} else {
// 			j = s.top().first;
// 		}

// 		ans.push_back(i - j);

// 		s.push({i, A[i]});

// 	}

// 	return ans;

// }

vector<int> f(int A[], int n) {

	vector<int> ans;
	stack<int> s; // monotonic stack (index)

	for (int i = 0; i < n; i++) {

		// to find the span for the ith day, find out what the index of the nearest greater element to the left of A[i]

		while (!s.empty() and A[s.top()] <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			j = -1;
		} else {
			j = s.top();
		}

		ans.push_back(i - j);

		s.push(i);

	}

	return ans;

}

int main() {

	int A[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(A) / sizeof(int);

	vector<int> ans = f(A, n);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}