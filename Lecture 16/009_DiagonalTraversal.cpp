/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>

using namespace std;

void printDiagonal(int mat[][10], int m, int n, int i, int j) {

	// print the diagonal in the mat[][] that starts at the i,jth index

	int len = min(m - i, n - j);
	for (int k = 0; k < len; k++) {
		cout << mat[i + k][j + k] << " ";
	}
	cout << endl;

}

void traverseDiagonally(int mat[][10], int m, int n) {

	// 1. print all the diagonals that start at (i, 0)

	for (int i = 0; i < m; i++) {

		printDiagonal(mat, m, n, i, 0);

	}

	// 2. print all the diagonals that start at (0, j)

	for (int j = 1; j < n; j++) {

		printDiagonal(mat, m, n, 0, j);

	}

}

int main() {

	int mat[10][10] = {
		{11, 12, 13, 14},
		{15, 16, 17, 18},
		{19, 20, 21, 22}
	};

	int m = 3;
	int n = 4;

	traverseDiagonally(mat, m, n);

	return 0;
}