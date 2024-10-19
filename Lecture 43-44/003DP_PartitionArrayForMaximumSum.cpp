#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int f(const vector<int>& arr, int n, int k, int i) {

	// base case

	if (i == n) { // you've built a valid partition
		return 0;
	}

	// recursive case

	// f(i) = find the maximum sum we can obtain from partitioning the arr[i...n-1] such that size of each subarray is <= k

	// decide the next cut

	int maxSoFar = INT_MIN;
	int maxVal_ij = 0;

	for (int j = i; j <= i + k - 1 and j <= n - 1; j++) {

		maxVal_ij = max(maxVal_ij, arr[j]);

		// make a cut at index j

		// when you make a cut at index j, you generate a subarray from index i to j

		maxSoFar = max(maxSoFar, maxVal_ij * (j - i + 1) + f(arr, n, k, j + 1));

	}

	return maxSoFar;

}

int fTopDown(const vector<int>& arr, int n, int k, int i, vector<int>& dp) {

	// lookup

	if (dp[i] != -1) {
		return dp[i];
	}

	// base case

	if (i == n) { // you've built a valid partition
		return dp[i] = 0;
	}

	// recursive case

	// f(i) = find the maximum sum we can obtain from partitioning the arr[i...n-1] such that size of each subarray is <= k

	// decide the next cut

	int maxSoFar = INT_MIN;
	int maxVal_ij = 0;

	for (int j = i; j <= i + k - 1 and j <= n - 1; j++) {

		maxVal_ij = max(maxVal_ij, arr[j]);

		// make a cut at index j

		// when you make a cut at index j, you generate a subarray from index i to j

		maxSoFar = max(maxSoFar, maxVal_ij * (j - i + 1) + fTopDown(arr, n, k, j + 1, dp));

	}

	return dp[i] = maxSoFar;

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {

	int n = arr.size();

	// return f(arr, n, k, 0);

	vector<int> dp(n + 1, -1);

	return fTopDown(arr, n, k, 0, dp);
}

int main() {

	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;

	cout << maxSumAfterPartitioning(arr, k) << endl;

	return 0;
}