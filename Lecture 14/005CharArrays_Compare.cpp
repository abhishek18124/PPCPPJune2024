#include<iostream>
#include<cstring>

using namespace std;

// len(s1) = m
// len(s2) = n

// steps = min(m, n)

int stringCompare(char s1[], char s2[]) {

	int i = 0;
	int j = 0;

	while (s1[i] != '\0' and s2[j] != '\0') {

		if (s1[i] > s2[j]) {

			// s1 > s2

			return 1;

		}

		if (s1[i] < s2[j]) {

			// s1 < s2

			return -1;

		}

		i++;
		j++;

	}

	if (s1[i] == '\0' and s2[j] == '\0') {

		return 0;

	} else if (s1[i] == '\0') { // s2[j] != '\0'

		// len(s1) < len(s2) therefore s1 < s2

		return -1;

	} else {

		// s1[i] != '\0' and s2[j] == '\0'

		// len(s1) > len(s2) therefor s1 > s2

		return 1;

	}


}

int main() {

	char s1[] = "abc";
	char s2[] = "abcde";

	// int ans = stringCompare(s1, s2);

	int ans = strcmp(s1, s2);

	if (ans == 0) {
		cout << s1 << " is equal to " << s2 << endl;
	} else if (ans > 0) {
		cout << s1 << " > " << s2 << endl;
	} else {
		cout << s1 << " < " << s2 << endl;
	}

	return 0;
}