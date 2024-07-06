#include<iostream>

using namespace std;

// time : O(mn)

bool isPresent(int mat[][3], int m, int n, int t) {

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			if (mat[i][j] == t) {

				// t found at the (i, j)th index of mat[][]

				return true;

			}

		}

	}

	// t not found in mat[][]

	return false;

}

int main() {

	int mat[][3]  = {
		{50, 80, 20},
		{90, 10, 70},
		{60, 30, 40}
	};

	int m = 3;
	int n = 3;

	int t = 100;

	isPresent(mat, m, n, t) ? cout << t << " found" << endl : cout << t << " not found" << endl;

	return 0;
}