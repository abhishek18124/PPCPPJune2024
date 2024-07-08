#include<iostream>

using namespace std;

int main() {

	int arr[5];

	cout << sizeof(arr) << "B" << endl;

	char brr[10];

	cout << sizeof(brr) << "B" << endl;

	double crr[20];

	cout << sizeof(crr) << "B" << endl;

	int drr[5];

	drr[0] = 10;
	drr[1] = 20;
	drr[2] = 30;
	drr[3] = 40;
	drr[4] = 50;

	cout << "drr[0] = " << drr[0] << endl;
	cout << "drr[1] = " << drr[1] << endl;
	cout << "drr[2] = " << drr[2] << endl;
	cout << "drr[3] = " << drr[3] << endl;
	cout << "drr[4] = " << drr[4] << endl << endl;

	for (int i = 0; i < 5; i++) {

		cout << "drr[" << i << "] = " << drr[i] << endl;

	}

	return 0;
}