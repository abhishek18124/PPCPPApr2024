// 1 <= n <= 100

#include<iostream>

using namespace std;

int main() {

	int A[100]; // based on constraints

	int n;
	cin >> n;

	// 1. read values into the array

	// cin >> A[0];
	// cin >> A[1];
	// cin >> A[2];
	// ...

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	// 2. print the values in the array

	for (int i = 0; i <= n - 1; i++) {
		cout << A[i] << " ";
	}

	cout << endl;


	// 3. print the values in the array in reverse

	for (int i = n - 1; i >= 0; i--) {
		cout << A[i] << " ";
	}

	cout << endl;


	return 0;
}