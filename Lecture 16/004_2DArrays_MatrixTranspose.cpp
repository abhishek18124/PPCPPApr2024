/*

	Constraints :

	0 < n <= 10

*/

#include<iostream>

using namespace std;

// (n^2 - n) / 2 swaps

// time = (n^2-n)/2.const ~ O(n^2)

void transpose(int mat[][10], int n) { // by default mat[][] is passed-by-reference

	for (int i = 0; i <= n - 2; i++) {

		for (int j = i + 1; j <= n - 1; j++) {

			swap(mat[i][j], mat[j][i]);

		}

	}

}

int main() {

	int n;
	cin >> n;

	int mat[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	cout << "matrix before transpose = " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;

	transpose(mat, n);

	cout << "matrix after transpose = " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}