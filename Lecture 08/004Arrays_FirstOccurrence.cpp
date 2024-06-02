#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	int i;

	for (i = 0; i < n; i++) { // n steps.const ~ O(n)

		if (arr[i] == t) {

			// you've found the t at the ith index

			cout <<  t << " found at index " << i << endl;
			break;

		}

	}

	if (i == n) {
		cout << t << " not found" << endl;
	}

	return 0;
}