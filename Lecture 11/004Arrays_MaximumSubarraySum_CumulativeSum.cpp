// constraints : n <= 100

#include<iostream>
#include<climits>

using namespace std;

// time : n^2.c + n.c ~ O(n^2)
// space : O(n)

int maximumSubarraySumOptimised(int arr[], int n) {

	int csum[101]; // based on constraints
	csum[0] = 0;

	for (int i = 1; i <= n; i++) { // n.c
		csum[i] = csum[i - 1] + arr[i - 1];
	}

	for (int i = 0; i <= n; i++) {
		cout << csum[i] << " ";
	}

	cout << endl;

	int maxSoFar = INT_MIN;

	for (int i = 0; i < n; i++) { // n^2.c

		for (int j = i; j < n; j++) {

			int sum = csum[j + 1] - csum[i];
			maxSoFar = max(maxSoFar, sum);

		}

	}

	return maxSoFar;

}

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySumOptimised(arr, n) << endl;

	return 0;
}