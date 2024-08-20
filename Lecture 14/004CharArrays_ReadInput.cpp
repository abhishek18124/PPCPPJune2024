// n <= 100

#include<iostream>

using namespace std;

void readString(char str[], char dlim = '\n') {

	char ch;
	int i = 0;

	while (true) {

		ch = cin.get();
		if (ch == dlim) { // '\n' is a.k.a delimiting char
			break;
		}

		str[i] = ch;
		i++;

	}

	str[i] = '\0';

}

int main() {

	char str[101]; // based on constraints

	// cin >> str; // '/0' is added automatically

	// readString(str);

	cin.getline(str, 5, '$');

	cout << str << endl;

	return 0;
}