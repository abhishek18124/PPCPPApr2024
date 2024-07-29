#include<iostream>

using namespace std;

bool f(int X[], int n, int i) {

	// base case

	if (i == n - 1) {

		// check if X[n-1...n-1] is sorted

		return true;

	}

	// recursive case

	// f(i) = check if X[i...n-1] is sorted or not

	return X[i] < X[i + 1] and f(X, n, i + 1);

}

int main() {

	int X[] = {1, 2, 3, 4, 5};
	int n = sizeof(X) / sizeof(int);

	f(X, n, 0) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}