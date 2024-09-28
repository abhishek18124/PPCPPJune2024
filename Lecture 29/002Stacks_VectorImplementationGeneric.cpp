#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class stack {

	vector<T> v; // internal repr. of stack

public :

	void push(T val) { // const
		v.push_back(val);
	}

	void pop() {
		v.pop_back();
	}

	int size() {
		return v.size();
	}

	T top() {
		return v.back();
	}

	bool empty() {
		return v.empty();
	}

};

int main() {

	stack<string> s;

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.push("e");
	s.push("d");
	s.push("c");
	s.push("b");
	s.push("a");

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	return 0;
}