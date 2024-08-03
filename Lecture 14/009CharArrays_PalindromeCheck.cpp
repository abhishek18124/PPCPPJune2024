#include<iostream>
#include<cstring>

using namespace std;

// bool isPalindrome(char str[]) {

// 	int n = strlen(str);

// 	int i = 0;
// 	int j = n - 1;

// 	while (i < j) {

// 		if (str[i] == str[j]) {

// 			i++;
// 			j--;

// 		} else {

// 			// str[] is not a palindrome

// 			return false;

// 		}

// 	}

// 	// str[] is a palindrome

// 	return true;

// }

bool isPalindrome(char str[]) {

	int n = strlen(str);

	int i = 0;
	int j = n - 1;

	while (i < j) {

		if (str[i] != str[j]) {

			// str[] is not a palindrome

			return false;

		}

		// str[i] is equal to str[j]

		i++;
		j--;

	}

	// str[] is a palindrome

	return true;

}

int main() {

	char str[] = "racecar";

	isPalindrome(str) ? cout << "palindrome" << endl : cout << "not a palindrome" << endl;

	return 0;
}