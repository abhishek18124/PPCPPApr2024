#include<iostream>

using namespace std;

int f(int X[], int n, int t, int i) {

	// base case

	if (i == n) {

		// find the index of 1st occ. of t in X[n...n-1] = {}
		return -1;

	}

	// recursive case

	// f(i) = find the index of 1st occ. of t in X[i...n-1]

	if (X[i] == t) {
		return i;
	}

	// ask your friend to find the index of 1st occ. of t in X[i+1...n-1]

	return f(X, n, t, i + 1);

}

int main() {

	int X[] = {10, 20, 30, 20, 30};
	int n = sizeof(X) / sizeof(int);
	int t = 100;

	cout << f(X, n, t, 0) << endl;

	return 0;
}