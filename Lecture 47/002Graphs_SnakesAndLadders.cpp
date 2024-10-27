/*

Snake and Ladders Game

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap; // to store the graph representation

public :

	void addEdge(T u, T v) {
		// insert a directed edge between vertex 'u' and 'v'
		neighbourMap[u].push_back(v);
	}

	int bfs(T s, T d) {

		map<T, int> distMap; // to store the mapping between vertices &
		// their shortest dist from the src vertex
		distMap[s] = 0;

		unordered_set<T> visited; // to keep track of visited vertices
		queue<T> q; // to keep track of visited & un-explored vertices

		map<T, T> parentMap;
		parentMap[s] = s;

		// mark 's' as visited
		visited.insert(s);
		q.push(s);

		while (!q.empty()) {
			T front = q.front();
			q.pop();

			// explore 'front'

			list<T> ngblist = neighbourMap[front];
			for (T ngb : ngblist) {
				if (visited.find(ngb) == visited.end()) {
					// ngb is not yet visited
					visited.insert(ngb);
					q.push(ngb);
					distMap[ngb] = distMap[front] + 1; // front is the parent of ngb in the BFS tree
					parentMap[ngb] = front;
				}
			}

		}

		// for (pair<T, int> p : distMap) {
		// 	cout << p.first << " : " << p.second << endl;
		// }

		// cout << endl;

		// for (pair<T, T> p : parentMap) {
		// 	cout << p.first << " : " << p.second << endl;
		// }

		vector<T> path;

		T start = d;

		while (parentMap[start] != start) {
			path.push_back(start);
			start = parentMap[start];
		}

		path.push_back(s);

		reverse(path.begin(), path.end());

		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << " ";
		}

		cout << endl;

		return distMap[d];
	}

	void print() {
		for (pair<T, list<T>> vertex : neighbourMap) {
			T vertexLabel = vertex.first;
			list<T> neighbourList = vertex.second;
			cout << vertexLabel << " : ";
			for (T neighbour : neighbourList) {
				cout << neighbour << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

};

int minDiceThrows(int n,
                  vector<pair<int, int>> snakes,
                  vector<pair<int, int>> ladders) {

	vector<int> wgtMap(n + 1, 0);

	for (pair<int, int> snakePos : snakes) {
		int startPos = snakePos.first;
		int endPos = snakePos.second;
		wgtMap[startPos] = endPos - startPos;
	}

	for (pair<int, int> ladderPos : ladders) {
		int startPos = ladderPos.first;
		int endPos = ladderPos.second;
		wgtMap[startPos] = endPos - startPos;
	}

	graph<int> g;

	for (int u = 1; u < n; u++) {

		if (wgtMap[u] != 0) {
			// there is a snake or ladder at cell u therefore you cannot roll die on cell u
			continue;
		}

		for (int d = 1; d <= 6; d++) {

			int v = u + d;

			if (v <= n) {

				// check if there is a snake or ladder at cell v

				int v_ = v + wgtMap[v];

				// ? = length of snake if there is a snake on cell v
				// ? = length of the ladder if there is a ladder on cell v
				// ? = 0 if there is no snake or ladder on cell v

				g.addEdge(u, v_);

			}

		}

	}

	return g.bfs(1, n);

}

int main() {

	int n = 36;

	vector<pair<int, int>> snakes  = {
		{17, 4},
		{20, 6},
		{24, 16},
		{32, 30},
		{34, 12}
	};

	vector<pair<int, int>> ladders = {
		{2, 15},
		{5, 7},
		{9, 27},
		{18, 29},
		{25, 35}
	};

	cout << minDiceThrows(n, snakes, ladders) << endl;

	return 0;
}