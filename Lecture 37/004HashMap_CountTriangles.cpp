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


// time : on. avg O(n)
// space : n + n ~ O(n) due to xFreqMap and yFreqMap when every point in the plane has unique x and y coordinate

int countTrainglesOptimised(const vector<Point>& points) {

	unordered_map<int, int> xFreqMap;
	unordered_map<int, int> yFreqMap;

	for (Point p : points) { // on. avg. linear

		xFreqMap[p.x]++;
		yFreqMap[p.y]++;

	}

	int cnt = 0; // to track the total no. of valid triangles in the 2d plane

	for (Point pivot : points) { // on. avg. linear

		// cnt no. of right angles triangles that are axis-parallel around the pivot

		int a = xFreqMap[pivot.x]; // to track no. of points in the 2d plane whose x-coor matches pivot.x
		int b = yFreqMap[pivot.y]; // to track no. of points in the 2d plane whose y-coor matches pivot.y

		cnt += (a - 1) * (b - 1); // we subtract -1 from a and b to exlude pivot

	}

	return cnt;

}


// time : O(n^2)
// space: O(1)

int countTraingles(const vector<Point>& points) {

	int cnt = 0; // to track the total no. of valid triangles in the 2d plane

	for (Point pivot : points) {

		// cnt no. of right angles triangles that are axis-parallel around the pivot

		int a = 0; // to track no. of points in the 2d plane whose x-coor matches pivot.x
		int b = 0; // to track no. of points in the 2d plane whose y-coor matches pivot.y

		for (Point p : points) {

			if (p.x == pivot.x) {
				a++;
			}

			if (p.y == pivot.y) {
				b++;
			}

		}

		cnt += (a - 1) * (b - 1); // we subtract -1 from a and b to exlude pivot

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

	cout << countTraingles(points) << endl;

	cout << countTrainglesOptimised(points) << endl;


	return 0;
}