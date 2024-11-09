#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> s) {

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

}

void insertAtBottom(stack<int>& s, int data) {

	// base case

	if (s.empty()) {
		s.push(data);
		return;
	}

	// recursive case

	int x = s.top();
	s.pop();

	insertAtBottom(s, data);

	s.push(x);

}

// t(n) = t(n-1) + n.c
// t(0) = c

// time : O(n^2)
// space: O(n) due to fn call stack

void reverseStack(stack<int>& s) {

	// base case

	if (s.empty()) {
		return;
	}

	// recursive case

	int x = s.top();
	s.pop();

	reverseStack(s);

	insertAtBottom(s, x);

}

int main() {

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	print(s);

	reverseStack(s);

	print(s);

	return 0;
}