/*

Given a m x n grid filled with non-negative numbers, find a path from (0, 0) to (m-1, n-1),
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example :
	Input: grid = [[1,3,1],
	               [1,5,1],
	               [4,2,1]]

	Output: 7
	Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Constraints :
	1 <= m, n <= 200
	0 <= grid[i][j] <= 100

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int f(const vector<vector<int>>& grid, int m, int n, int i, int j) {

	// base case

	if (i == m - 1 and j == n - 1) {

		// f(m-1, n-1) = find the minimum sum path from (m-1, n-1) to (m-1, n-1)

		return grid[i][j];
	}

	// if(i == m || j == n) {
	// 	return INT_MAX;
	// }

	// recursive cases

	// f(i, j) = find the minimum sum path from (i, j) to (m-1, n-1)

	if (i == m - 1) {
		return grid[i][j] + f(grid, m, n, i, j + 1);
	}

	if (j == n - 1) {
		return grid[i][j] + f(grid, m, n, i + 1, j);
	}

	int X = f(grid, m, n, i, j + 1);
	int Y = f(grid, m, n, i + 1, j);

	return grid[i][j] + min(X, Y);
}

// time : O(mn)
// space: O(mn) due to dp[][]

int fBottomUp(const vector<vector<int>>& grid, int m, int n) {

	vector<vector<int>> dp(m, vector<int>(n));

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {

			// dp[i][j] = f(i, j) = find the minimum sum path from (i, j) to (m-1, n-1)

			if (i == m - 1 and j == n - 1) {
				dp[i][j] = grid[i][j];
			} else if (i == m - 1) {
				dp[i][j] = grid[i][j] + dp[i][j + 1];
			} else if (j == n - 1) {
				dp[i][j] = grid[i][j] + dp[i + 1][j];
			} else {
				dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
			}

		}
	}

	int x = 0;
	int y = 0;

	while (!(x == m - 1 and y == n - 1)) {

		cout << "(" << x << ", " << y << ")" << endl;

		if (y + 1 < n and dp[x][y] == grid[x][y] + dp[x][y + 1]) {
			y++;
		} else {
			x++;
		}

	}

	cout << "(" << x << ", " << y << ")" << endl;

	return dp[0][0]; // at the 0,0th index of dp[][] we store f(0, 0)

}

// time : O(mn)
// space: 2n ~ O(n) due to nextRow and curRow

int fBottomUpSpaceOptimised(const vector<vector<int>>& grid, int m, int n) {

	vector<int> nextRow(n, 0); // 0 init is not needed (optional) => represents the case when i is equal to m

	for (int i = m - 1; i >= 0; i--) {

		vector<int> curRow(n);

		for (int j = n - 1; j >= 0; j--) {

			// dp[i][j] = f(i, j) = find the minimum sum path from (i, j) to (m-1, n-1)

			if (i == m - 1 and j == n - 1) {
				curRow[j] = grid[i][j];
			} else if (i == m - 1) {
				curRow[j] = grid[i][j] + curRow[j + 1];
			} else if (j == n - 1) {
				curRow[j] = grid[i][j] + nextRow[j];
			} else {
				curRow[j] = grid[i][j] + min(curRow[j + 1], nextRow[j]);
			}

		}

		// nextRow = curRow; // here we are using copy semantics, elements of curRow is copied into nextRow (slow)
		nextRow = move(curRow); // here we are using move semantics, nextRow is stealing the contents of curRow (fast)

	}

	return nextRow[0]; // it represents dp[0][0]


}

// time : O(mn)
// space: n ~ O(n) due to dp[]

int fBottomUpMoreSpaceOptimised(const vector<vector<int>>& grid, int m, int n) {

	vector<int> dp(n, 0); // 0 init is not needed (optional) => represents the case when i is equal to m

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {

			// dp[i][j] = f(i, j) = find the minimum sum path from (i, j) to (m-1, n-1)

			if (i == m - 1 and j == n - 1) {
				dp[j] = grid[i][j];
			} else if (i == m - 1) {
				dp[j] = grid[i][j] + dp[j + 1];
			} else if (j == n - 1) {
				dp[j] = grid[i][j] + dp[j];
			} else {
				dp[j] = grid[i][j] + min(dp[j + 1], dp[j]);
			}

		}
	}

	return dp[0]; // at the 0th index of dp[] we store f(0, 0)



}

int main() {

	vector<vector<int>> grid = {
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1}
	};

	int m = grid.size();
	int n = grid[0].size();

	cout << f(grid, m, n, 0, 0) << endl;

	cout << fBottomUp(grid, m, n) << endl;

	cout << fBottomUpSpaceOptimised(grid, m, n) << endl;

	cout << fBottomUpMoreSpaceOptimised(grid, m, n) << endl;

	return 0;
}