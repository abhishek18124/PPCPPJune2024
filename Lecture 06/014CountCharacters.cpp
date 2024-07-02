#include<iostream>

using namespace std;

int main() {

	int cnt = 0; // to track the no. of characters

	char ch;

	while (true) {

		// cin >> ch; // ignores whitespaces
		ch = cin.get(); // reads whitespaces (' ', '\t', '\n')

		if (ch == '$') {
			break;
		}

		cnt++;

	}

	cout << "cnt = " << cnt << endl;

	return 0;
}