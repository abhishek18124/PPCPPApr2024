// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

// 1. brute-force approach - time : O(m^2.n^2)

vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// find the manhattan dist of all the cells from the (i, j)th cell
				for (int ii = 0; ii < m; ii++) {
					for (int jj = 0; jj < n; jj++) {
						// find the manhanttan dist b/w (i, j) and (ii, jj)th cell
						dist[ii][jj] = min(dist[ii][jj], abs(ii - i) + abs(jj - j));
					}
				}
			}
		}
	}

	return dist;

}

// time : O(mn) multi-source BFS

vector<vector<int>> updateMatrixOptimised(const vector<vector<int>>& mat) {

	queue<pair<int, int>> q; // each vertex in my implicit is represented by its coordinates in the mat

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// (i, j)th cell corresponds to a src vertex
				dist[i][j] = 0;
				q.push({i, j});
			}
		}
	}

	int dx[] = {0, 0, -1, 1};
	int dy[] = {1, -1, 0, 0};

	while (!q.empty()) {

		pair<int, int> front = q.front();
		q.pop();

		int i = front.first;
		int j = front.second;

		// int ii = i;
		// int jj = j + 1;

		// if (ii >= 0 and ii < m and jj >= 0 and jj < n and dist[ii][jj] == INT_MAX) {
		// 	q.push({ii, jj});
		// 	dist[ii][jj] = dist[i][j] + 1;
		// }

		// ii = i;
		// jj = j - 1;

		// if (ii >= 0 and ii < m and jj >= 0 and jj < n and dist[ii][jj] == INT_MAX) {
		// 	q.push({ii, jj});
		// 	dist[ii][jj] = dist[i][j] + 1;
		// }

		// ii = i - 1;
		// jj = j;

		// if (ii >= 0 and ii < m and jj >= 0 and jj < n and dist[ii][jj] == INT_MAX) {
		// 	q.push({ii, jj});
		// 	dist[ii][jj] = dist[i][j] + 1;
		// }

		// ii = i + 1;
		// jj = j;

		// if (ii >= 0 and ii < m and jj >= 0 and jj < n and dist[ii][jj] == INT_MAX) {
		// 	q.push({ii, jj});
		// 	dist[ii][jj] = dist[i][j] + 1;
		// }

		for (int k = 0; k < 4; k++) {
			int ii = i + dx[k];
			int jj = j + dy[k];
			if (ii >= 0 and ii < m and jj >= 0 and jj < n and dist[ii][jj] == INT_MAX) {
				q.push({ii, jj});
				dist[ii][jj] = dist[i][j] + 1;
			}
		}

	}

	return dist;

}

int main() {

	vector<vector<int>> mat = {
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	// vector<vector<int>> dist = updateMatrix(mat);

	vector<vector<int>> dist = updateMatrixOptimised(mat);

	for (vector<int> row : dist) {
		for (int col : row) {
			cout << col << " ";
		}
		cout << endl;
	}

	return 0;
}