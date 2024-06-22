// m <= 100

#include<iostream>

using namespace std;

int main() {

	int m;
	cin >> m;

	int arr[101]; // based on constraints

	for (int i = 0; i <= m; i++) {
		arr[i] = 1;
	}

	arr[0] = 0;
	arr[1] = 0;

	// // approach - 1

	// for (int i = 2; i <= m; i++) {

	// 	if (arr[i] == 1) {

	// 		// i is a prime no. therefore none of its multiples can be prime, so cancel them out

	// 		for (int j = 2 * i; j <= m; j = j + i) {

	// 			arr[j] = 0;

	// 		}

	// 	}

	// }

	// // approach - 2

	// for (int i = 2; i <= m; i++) {

	// 	if (arr[i] == 1) {

	// 		// i is a prime no. therefore none of its multiples can be prime, so cancel them out

	// 		for (int j = i * i; j <= m; j = j + i) {

	// 			arr[j] = 0;

	// 		}

	// 	}

	// }

	// approach - 3 // mloglogm <= m * root(m)

	for (int i = 2; i * i <= m; i++) { // i <= root(m)

		if (arr[i] == 1) {

			// i is a prime no. therefore none of its multiples can be prime, so cancel them out

			for (int j = i * i; j <= m; j = j + i) {

				arr[j] = 0;

			}

		}

	}


	for (int i = 2; i <= m; i++) {

		if (arr[i] == 1) {

			// i is a prime number

			cout << i << " ";

		}

	}

	cout << endl;

	return 0;
}