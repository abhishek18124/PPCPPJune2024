#include<iostream>

using namespace std;

// time : O(mlogn)

bool isPresent(int mat[][3], int m, int n, int t) {

	for (int i = 0; i < m; i++) {
		// if (binary_search( mat[i], mat[i + 1], t)) { // fails when m, and n donot match constraints
		// 	return true;
		// }

		if (binary_search( mat[i], mat[i] + n, t)) {
			return true;
		}
	}

	return false;

}


int main() {

	int mat[][3] = {
		{40, 50, 60},
		{10, 20, 30},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	int t = 50;

	isPresent(mat, m, n, t) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}