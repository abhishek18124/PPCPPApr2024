/*

Suppose there is a ladder with n steps. A person standing at the bottom of the ladder and wants to
reach to its top. Assume the person can take atmost k steps at a time. Then, count the number
of ways, the person can reach the top of the ladder.

Example
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1],
	              [1, 1, 2],
	              [1, 2, 1],
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/
#include<iostream>
#include<vector>

using namespace std;

vector<int> path;

int f(int n, int k, int i) {

	// base case

	if (i == n) {

		for (int k = 0; k < path.size(); k++) {
			cout << path[k] << " ";
		}
		cout << endl;
		return 1;

	}

	// recursive case

	// f(i) : count no. of ways to go from i to n

	// jump size = 1 => f(i+1)
	// jump size = 2 => f(i+2)
	// jump size = 3 => f(i+3)
	// ...
	// jump size = k => f(i+k)

	int cnt = 0;

	for (int j = 1; j <= k; j++) {

		if (i + j <= n) {

			// path.push_back(j);
			// i = i + j;
			// cnt += f(n, k, i);
			// i = i - j; // backtracking
			// path.pop_back(); // backtracking

			path.push_back(j);
			cnt += f(n, k, i + j);
			path.pop_back(); // backtracking


		}

	}

	return cnt;

}

int main() {

	int n = 4;
	int k = 3;

	cout << f(n, k, 0) << endl;

	return 0;
}