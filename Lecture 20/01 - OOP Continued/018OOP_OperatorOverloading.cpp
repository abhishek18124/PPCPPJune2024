#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		cout << "\ninside the parameterised constructor of the \'customer\' class\n" << endl;
		name = n;
		age = a;
		gender = g;
		credits = c;
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl << endl;
	}

	int operator+(const customer& c) { // c is a const ref to c2
		return age + c.age;
	}

	int operator*(const customer& c) {
		return age * c.age;
	}

	bool operator>(const customer& c) {
		return age > c.age;
	}

};

int operator-(customer c1, customer c2) {
	return c1.age - c2.age;
}

// void operator<<(ostream& cout, customer& c) {
// 	cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
// }

ostream& operator<<(ostream& cout, customer& c) {
	cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	return cout;
}

int main() {

	customer c1("Ramanujan", 32, 'M', 1729);
	customer c2("Aryabhata", 74, 'M', 0);

	cout << c1 + c2 << endl; // c1.operator+(c2)

	cout << c1 * c2 << endl; // c1.operator*(c2)

	if (c1 > c2) { // c1.operator>(c2)

		cout << c1.name << " is older than " << c2.name << endl;

	} else {

		cout << c2.name << " is older than " << c1.name << endl;

	}

	cout << c1 - c2 << endl; // c1.operator-(c2) // operator-(c1, c2)

	cout << c1; // operator<<(cout, c1)

	// cout << c1 << c2;
	// operator<<(cout, c1) << c2;
	// void << c2;

	cout << c1 << c2;
	// operator<<(cout, c1) << c2;
	// cout << c2;
	// operator<<(cout, c2);
	// cout;

	return 0;

}