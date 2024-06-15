#include<iostream>

using namespace std;

int upperBound(int arr[], int n, int t) {

	int ans = -1;

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		int m = s + (e - s) / 2;
		if (arr[m] == t) {
			ans = m;
			// reduce the search space from [s, e] to [m+1, e]
			s = m + 1;
		} else if (t > arr[m]) {
			// reduce the search space from [s, e] to [m+1, e]
			s = m + 1;
		} else {
			// t < arr[m]
			// reduce the search space from [s, e] to [s, m-1]
			e = m - 1;
		}

	}

	return ans;

}


int lowerBound(int arr[], int n, int t) {

	int ans = -1;

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		int m = s + (e - s) / 2;
		if (arr[m] == t) {
			ans = m;
			// reduce the search space from [s, e] to [s, m-1]
			e = m - 1;
		} else if (t > arr[m]) {
			// reduce the search space from [s, e] to [m+1, e]
			s = m + 1;
		} else {
			// t < arr[m]
			// reduce the search space from [s, e] to [s, m-1]
			e = m - 1;
		}

	}

	return ans;

}

int main() {

	int arr[] = {10, 20, 30, 30, 30, 30, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	int t = 30;

	int lb = lowerBound(arr, n, t);
	if (lb == -1) {
		cout << 0 << endl;
	} else {
		int ub = upperBound(arr, n, t);
		cout << ub - lb + 1 << endl;
	}

	return 0;
}