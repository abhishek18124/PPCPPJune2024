#include<iostream>
#include<stack>

using namespace std;

class custom_stack {

	stack<int> main_stack;
	stack<int> min_stack; // [hw] try to implement custom stack w/o using min_stack (extra space)

public :
	// time : O(1)
	void push(int data) {
		main_stack.push(data);
		if (min_stack.empty() || data <= min_stack.top()) {
			min_stack.push(data);
		}
	}
	// time : O(1) // make sure stack is non-empty otherwise behaviour is undefined
	void pop() {
		int temp = main_stack.top();
		main_stack.pop();
		if (min_stack.top() == temp) {
			min_stack.pop();
		}
	}

	int size() {
		return main_stack.size();
	}

	bool empty() {
		return main_stack.empty();
	}

	// time : O(1) // make sure stack is non-empty otherwise behaviour is undefined
	int top() {
		return main_stack.top();
	}

	// time : O(1) // make sure stack is non-empty otherwise behaviour is undefined
	int getMin() {
		return min_stack.top();
	}

};

int main() {

	custom_stack cs;

	cs.push(10);
	cs.push(20);

	cout << cs.top() << " " << cs.getMin() << endl;

	cs.push(0);
	cs.push(30);

	cout << cs.top() << " " << cs.getMin() << endl;

	cs.pop();

	cout << cs.top() << " " << cs.getMin() << endl;

	cs.pop();

	cout << cs.top() << " " << cs.getMin() << endl;

	return 0;
}
