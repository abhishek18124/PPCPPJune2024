#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

};

void printByVal(customer c) { // by default customer object is passed-by-value

	cout << "name = " << c.name << endl;
	cout << "age = " << c.age << endl;
	cout << "gender = " << c.gender << endl;
	cout << "credits = " << c.credits << endl << endl;

}

void printByRef(customer& c) { // by default customer object is passed-by-value

	c.age++;
	cout << "name = " << c.name << endl;
	cout << "age = " << c.age << endl;
	cout << "gender = " << c.gender << endl;
	cout << "credits = " << c.credits << endl << endl;

}

void printByConstRef(const customer& c) { // by default customer object is passed-by-value

	// c.age++; // c is const ref
	cout << "name = " << c.name << endl;
	cout << "age = " << c.age << endl;
	cout << "gender = " << c.gender << endl;
	cout << "credits = " << c.credits << endl << endl;

}

int main() {

	customer c1;

	c1.name = "Ramanujan";
	c1.age = 32;
	c1.gender = 'M';
	c1.credits = 1729;

	// printByVal(c1);
	// printByRef(c1);
	printByConstRef(c1);

	cout << c1.age << endl;

	customer c2;

	c2.name = "Aryabhata";
	c2.age = 74;
	c2.gender = 'M';
	c2.credits = 0;

	// printByVal(c2);
	// printByRef(c2);
	printByConstRef(c2);

	cout << c2.age << endl;

	return 0;
}