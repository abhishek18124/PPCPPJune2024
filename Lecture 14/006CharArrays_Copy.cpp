#include<iostream>
#include<cstring>

using namespace std;

// len(s1) = m
// len(s2) = n

// steps = n

void stringCopy(char s1[], char s2[]) {

	int i = 0; // to iterate over s1[]
	int j = 0; // to iterate over s2[]

	while (s2[j] != '\0') {
		s1[i] = s2[j];
		i++;
		j++;
	}

	s1[i] = '\0';

}

int main() {

	char s1[100] = "hello";
	char s2[] = "abc";

	cout << s1 << endl; // hello

	// stringCopy(s1, s2);

	strcpy(s1, s2);

	cout << s1 << endl; // abc

	return 0;
}