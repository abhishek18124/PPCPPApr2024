/*



Given a rod of length 'n' along with prices of its pieces of different lengths, design an algorithm to
compute the maximum profit we can make by cutting the rod and a selling its pieces.

Example :

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [1,  5,  8,  9,  10, 17, 17, 20]
	Output : 22

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [3,  5,  8,  9, 10, 17, 17, 20]
	Output : 24


*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int cnt1 = 0;

int f(int n, const vector<int>& p) {

	cnt1++;

	// base case

	if (n == 0) {

		// f(0) = find the max. profit given a rod of length 0

		return 0;

	}

	// recursive case

	// f(n) = find the max. profit given a rod of length n

	// decide the size of the next cut

	int maxSoFar = INT_MIN;

	for (int j = 1; j <= n; j++) {

		maxSoFar = max(maxSoFar, p[j - 1] + f(n - j, p));

	}

	return maxSoFar;

}

int cnt2 = 0;

int fTopDown(int n, const vector<int>& p, vector<int>& dp) {

	cnt2++;

	// lookup

	if (dp[n] != -1) {
		return dp[n];
	}

	// base case

	if (n == 0) {

		// f(0) = find the max. profit given a rod of length 0

		return  dp[n] = 0; // optional since base is already const

	}

	// recursive case

	// f(n) = find the max. profit given a rod of length n

	// decide the size of the next cut

	int maxSoFar = INT_MIN;

	for (int j = 1; j <= n; j++) {

		maxSoFar = max(maxSoFar, p[j - 1] + fTopDown(n - j, p, dp));

	}

	return  dp[n] = maxSoFar;

}

// time : O(n^2)
// space : O(n) due to dp[]

int fBottomUp(int n, const vector<int>& p) {

	vector<int> dp(n + 1);

	dp[0] = 0; // at the 0th index of dp[] we store f(0)

	for (int i = 1; i <= n; i++) {

		// dp[i] = f(i) = max. profit from a rod of length i

		// decide the size of the next cut

		int maxSoFar = INT_MIN;

		for (int j = 1; j <= i; j++) {

			maxSoFar = max(maxSoFar, p[j - 1] + dp[i - j]);

		}

		dp[i] = maxSoFar;

	}

	return dp[n]; // at the nth index of dp[] we store f(n)
}

int main() {

	vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20, 2, 4, 7, 8};
	int n = p.size();

	cout << f(n, p) << endl;

	cout << cnt1 << endl;

	vector<int> dp(n + 1, -1);

	cout << fTopDown(n, p, dp) << endl;

	cout << cnt2 << endl;

	cout << fBottomUp(n, p) << endl;

	return 0;
}