#include<iostream>
#define PI 3.14
#define PRINT cout <<
#define NEWLINE endl
#define SEMICOLON ;
#define F5 	for (int i = 1; i <= 5; i++) {cout << i << " ";}
#define F(n) 	for (int i = 1; i <= n; i++) {cout << i << " ";}
#define ll long long

using namespace std;

int main() {

	PRINT PI << NEWLINE SEMICOLON
	         PRINT 2 * PI << NEWLINE SEMICOLON

	         // F5

	         int n;
	cin >> n;

	F(n)

	return 0;
}