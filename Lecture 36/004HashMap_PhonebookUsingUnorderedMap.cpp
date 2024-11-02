/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {

	// e.g. Krishna -> 1234, 4567, ...
	//      Soumya -> 0102, 0000, ...
	//      ...

	unordered_map <string, vector<string>> phoneMap;

	phoneMap["Krishna"].push_back("1234");
	phoneMap["Krishna"].push_back("4567");
	phoneMap["Soumya"].push_back("0102");
	phoneMap["Chinmay"].push_back("0011");
	phoneMap["Chinmay"].push_back("0022");

	for (pair<string, vector<string>> contact : phoneMap) {
		string contactName = contact.first;
		vector<string> phoneNums = contact.second;
		cout << contactName << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}