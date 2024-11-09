/*
	Given N cartesian points in a 2D plane, count the number of right-angled triangles that
	can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.

	Examples

	Input : {(0, 0),
	         (2, 0),
	         (0, 1)}

	Output: 1

	Input : {(1, 2),
			 (2, 0),
			 (2, 2),
			 (2, 3),
			 (4, 2)}

	Output: 4
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

// time : O(n^2)

int findTriangles(const vector<Point>& points) {

	int cnt = 0; // to store the cnt of total valid triangles we find in the 2d plane

	for (Point p : points) {

		// find the no. of valid triangles with 'p' as the pivot

		// 1. find the no. of points in the 2d plane whose x-coordinate matches p.x

		// 2. find the no. of points in the 2d plane whose y-coordinate matches p.y

		int a = 0; // to track no. of points in the 2d plane whose x-coor matches p.x
		int b = 0; // to track no. of points in the 2d plane whose y-coor matches p.y

		for (Point pp : points) {
			if (pp.x == p.x) {
				a++;
			}
			if (pp.y == p.y) {
				b++;
			}
		}

		cnt += (a - 1) * (b - 1); // we are subtracting 1 from a and b because we don't want to count pivot 'p' while answering the questions 1 and 2


	}

	return cnt;

}

// time : O(n)
// space: O(n) due xFreqMap and yFreqMap when every point has a unique x-coor and unique y-coor

int findTrianglesOptimised(const vector<Point>& points) {

	unordered_map<int, int> xFreqMap;
	unordered_map<int, int> yFreqMap;

	for (Point p : points) {
		xFreqMap[p.x]++;
		yFreqMap[p.y]++;
	}

	int cnt = 0; // to store the cnt of total valid triangles we find in the 2d plane

	for (Point p : points) {

		// find the no. of valid triangles with 'p' as the pivot

		// 1. find the no. of points in the 2d plane whose x-coordinate matches p.x

		// 2. find the no. of points in the 2d plane whose y-coordinate matches p.y

		int a = xFreqMap[p.x]; // to track no. of points in the 2d plane whose x-coor matches p.x
		int b = yFreqMap[p.y]; // to track no. of points in the 2d plane whose y-coor matches p.y

		cnt += (a - 1) * (b - 1); // we are subtracting 1 from a and b because we don't want to count pivot 'p' while answering the questions 1 and 2

	}

	return cnt;

}

int main() {

	vector<Point> points = {
		Point(1, 2),
		Point(2, 0),
		Point(2, 2),
		Point(2, 3),
		Point(4, 2)
	};

	cout << findTriangles(points) << endl;
	cout << findTrianglesOptimised(points) << endl;

	return 0;
}