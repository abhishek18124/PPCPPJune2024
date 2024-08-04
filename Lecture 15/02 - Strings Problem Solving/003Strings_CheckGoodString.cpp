#include<iostream>
#include<string>

using namespace std;

// bool isGoodString(string str) { // n-steps

// 	for (int i = 0; i < str.size(); i++) {

// 		char ch = str[i];

// 		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'))	 {
// 			// ch is a consonant
// 			return false;
// 		}

// 	}

// 	return true;

// }

bool isGoodString(string str) { // n-steps

	for (char ch : str) {

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'))	 {
			// ch is a consonant
			return false;
		}

	}

	return true;

}

int main() {

	string str = "uoiea";

	isGoodString(str) ? cout << "good" << endl : cout << "not good" << endl;

	return 0;
}