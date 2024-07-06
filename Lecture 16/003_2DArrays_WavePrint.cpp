#include<iostream>

using namespace std;

void wavePrint(int arr[][3], int m, int n) { // by default, arr[][[] is passed by ref

	// iterate over the columns

	for (int j = 0; j <= n - 1; j++) {

		// print the jth column

		if (j % 2 == 0) {

			// jth column is even

			// iterate over the rows from top to down

			for (int i = 0; i <= m - 1; i++) {

				cout << arr[i][j] << " ";

			}

		} else {

			// jth column is odd

			// iterate over the rows from bottom to top

			for (int i = m - 1; i >= 0; i--) {

				cout << arr[i][j] << " ";

			}

		}

	}

}

int main() {

	int arr[][3] = {
		{10, 20, 30},
		{40, 50, 60},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	wavePrint(arr, m, n);

	return 0;
}