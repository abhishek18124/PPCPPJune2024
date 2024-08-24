#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int add1(int y) {
	return 1 + y;
}

int add2(int y) {
	return 2 + y;
}

int add3(int y) {
	return 3 + y;
}

class addx {

	int x;

public:

	addx(int x) {
		this->x = x;
	}

	int operator()(int y) {
		return y + x;
	}

};

int main() {

	vector<int> inp = {1, 2, 3, 4, 5};
	int n = inp.size();

	for (int i = 0; i < inp.size(); i++) {
		cout << inp[i] << " ";
	}

	cout << endl;

	vector<int> out(n);

	// transform(inp.begin(), inp.end(), out.begin(), add1);

	addx obj(1);

	transform(inp.begin(), inp.end(), out.begin(), obj);

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	// transform(inp.begin(), inp.end(), out.begin(), add2);

	addx obj2(2);
	transform(inp.begin(), inp.end(), out.begin(), obj2);


	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	// transform(inp.begin(), inp.end(), out.begin(), add3);

	transform(inp.begin(), inp.end(), out.begin(), addx(3));


	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;



	return 0;
}