#include<iostream>
#include<cstring> // to use memset

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};

	// int n = 5;
	int n = sizeof(A) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "] = " << A[i] << endl;
	}

	int B[] = {100, 200, 300};
	int m = sizeof(B) / sizeof(int);

	for (int i = 0; i < m; i++) {
		cout << "B[" << i << "] = " << B[i] << endl;
	}

	int C[5] = {1000, 2000};
	int k = sizeof(C) / sizeof(int);

	for (int i = 0; i < k; i++) {
		cout << "C[" << i << "] = " << C[i] << endl;
	}

	int D[5] = {};

	for (int i = 0; i < 5; i++) {
		cout << D[i] << " ";
	}

	cout << endl;

	int E[5] = {0};

	for (int i = 0; i < 5; i++) {
		cout << E[i] << " ";
	}

	cout << endl;

	int F[5];

	memset(F, 0, sizeof(F));

	for (int i = 0; i < 5; i++) {
		cout << F[i] << " ";
	}

	cout << endl;

	return 0;
}