#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise false

bool lengthComparator(string a, string b) {

	if (a.size() < b.size()) {
		return true;
	}

	return false;

}

int main() {

	string arr[] = {"wxy", "z", "abcd", "ef"};
	int n = 4;

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	sort(arr, arr + n, lengthComparator);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}