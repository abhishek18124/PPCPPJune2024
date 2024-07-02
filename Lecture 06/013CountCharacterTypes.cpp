#include<iostream>

using namespace std;

int main() {

	int lCount = 0; // to track the no. of lowercase letters
	int uCount = 0; // to track the no. of uppercase letters
	int dCount = 0; // to track the no. of digits
	int sCount = 0; // to track the no. of speical symbols
	int wCount = 0; // to track the no. of whitespaces

	char ch;

	while (true) {

		ch = cin.get();
		if (ch == '$') {
			break;
		}

		if (ch >= 'A' and ch <= 'Z') {
			uCount++;
		} else if (ch >= 'a' and ch <= 'z') {
			lCount++;
		} else if (ch >= '0' and ch <= '9') {
			dCount++;
		} else if (ch == ' ' or ch == '\t' or ch == '\n') {
			wCount++;
		} else {
			sCount++;
		}

	}

	cout << "lCount = " << lCount << endl;
	cout << "uCount = " << uCount << endl;
	cout << "dCount = " << dCount << endl;
	cout << "sCount = " << sCount << endl;
	cout << "wCount = " << wCount << endl;


	return 0;
}