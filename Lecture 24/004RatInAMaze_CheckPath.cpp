/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> check if there exists a path from src to dst

such at each step the rat can only move in the right or down direction.

Constraint

 1 <= m, n < 10

Example
	Input :

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}

	Output :

		true (Yes, a path exist from src to dst)

*/

#include<iostream>

using namespace std;

bool f(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (maze[i][j] == 'X') {
		return false;
	}

	if (i == m - 1 and j == n - 1) {
		return true;
	}

	// recursive case

	// f(i, j) = check if there exists a path from (i, j) to (m-1, n-1)th cell ?

	if (i == m - 1) {
		return f(maze, m, n, i, j + 1);
	}

	if (j == n - 1) {
		return f(maze, m, n, i + 1, j);
	}

	// decide the next step

	// option 1 : move right

	bool x = f(maze, m, n, i, j + 1);

	// option 2 : move down

	bool y = f(maze, m, n, i + 1, j);

	return x or y;

	// return f(maze, m, n, i, j+1) or f(maze, m, n, i+1, j);

}

bool f2(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) { // you've gone outside the grid
		return false;
	}

	if (maze[i][j] == 'X') { // you've reached a blocked cell
		return false;
	}

	if (i == m - 1 and j == n - 1) { // you've reached the destn
		return true;
	}

	// recursive case

	// f(i, j) = check if there exists a path from (i, j) to (m-1, n-1)th cell ?

	// decide the next step

	// option 1 : move right

	bool x = f2(maze, m, n, i, j + 1);

	// option 2 : move down

	bool y = f2(maze, m, n, i + 1, j);

	return x or y;

	// return f2(maze, m, n, i, j+1) or f2(maze, m, n, i+1, j);

}

int cnt = 0;

bool f3(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) { // you've gone outside the grid
		return false;
	}

	if (maze[i][j] == 'X') { // you've reached a blocked cell
		return false;
	}

	if (i == m - 1 and j == n - 1) { // you've reached the destn
		cnt++;
		return true;
	}

	// recursive case

	// f(i, j) = check if there exists a path from (i, j) to (m-1, n-1)th cell ?

	// decide the next step

	// option 1 : move right

	bool x = f3(maze, m, n, i, j + 1);

	// option 2 : move down

	bool y = f3(maze, m, n, i + 1, j);

	return x or y;

	// return f3(maze, m, n, i, j+1) or f3(maze, m, n, i+1, j); // don't do this if you also want count

}


int main() {

	char maze[][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};

	int m = 4;
	int n = 4;

	f(maze, m, n, 0, 0) ? cout << "true" << endl : cout << "false" << endl;
	f2(maze, m, n, 0, 0) ? cout << "true" << endl : cout << "false" << endl;
	f3(maze, m, n, 0, 0) ? cout << "true" << endl : cout << "false" << endl;

	cout << cnt << endl;

	return 0;
}