/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>

using namespace std;

void printDiagonal(int mat[][10], int m, int n, int i, int j) {

	// print the diagonal in the mat[][10] that starts at the (i, j)th index

	int dLen = min(m - i, n - j);

	for (int k = 0; k < dLen; k++) {

		cout << mat[i + k][j + k] << " ";

	}

	cout << endl;

}

void diagonalTraversal(int mat[][10], int m, int n) {

	// 1. print all the diagonals that start at (0, j) where 1<=j<=n-1

	for (int j = 1; j <= n - 1; j++) {

		printDiagonal(mat, m, n, 0, j);

	}

	// 2. print all the diagonals that start at (i, 0) where 0<=i<=m-1

	for (int i = 0; i <= m - 1; i++) {

		printDiagonal(mat, m, n, i, 0);

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

	diagonalTraversal(mat, m, n);

	return 0;
}