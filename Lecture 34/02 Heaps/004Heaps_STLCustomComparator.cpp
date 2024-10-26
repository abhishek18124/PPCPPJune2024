/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {
public:

	string name;
	int age;

	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}

};

class customerAgeComp {

public:

	// return true if you want a to be ordered before b otherwise return false

	// bool operator()(customer a, customer b) {
	// 	if (a.age < b.age) {
	// 		// since we are building a minHeap based on age, we want a to be ordered before b
	// 		return true;
	// 	}
	// 	return false;
	// }

	// return false if you want a to be given higer priority than b otherwise return true

	bool operator()(customer a, customer b) {
		if (a.age < b.age) {
			// since we are building a minHeap based on age, we want a to be given higher priority than b
			return false;
		}

		return true;
	}

};

int main() {

	priority_queue<customer, vector<customer>, customerAgeComp> m;

	m.push(customer("kartik", 20));
	m.push(customer("chinmay", 18));
	m.push(customer("stuti", 19));
	m.push(customer("akshat", 21));
	m.push(customer("rudra", 17));

	cout << m.size() << endl; // 5

	while (!m.empty()) {
		customer c = m.top();
		cout << c.name << " " << c.age << endl;
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl; // 0

	return 0;
}