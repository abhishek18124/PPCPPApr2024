#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

// 2n-1 ops i.e. O(n) e.g. 1 2 3 4 5 -6 (n push, n-1 pops)

vector<int> asteroidCollision(vector<int>& asteroids) {

	stack<int> s;

	for (int ast : asteroids) {

		if (ast < 0 and !s.empty() and s.top() > 0) {

			// simultate collisions

			bool flag = true; // assume ast will not be destroyed

			while (!s.empty() and s.top() > 0) {

				if (abs(ast) > s.top()) {
					// s.top() is destroyed
					s.pop();

				} else if (abs(ast) < s.top()) {
					// ast is destroyed
					flag = false;
					break;

				} else {
					// ast and s.top() both are destroyed
					s.pop();
					flag = false;
					break;

				}

			}

			if (flag == true) {
				s.push(ast);
			}

		} else {

			s.push(ast);

		}

	}

	vector<int> ans;

	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	vector<int> asteroids = {7, 3, -4, 5, 2, -8, 2, 4, 1, -4};

	vector<int> ans = asteroidCollision(asteroids);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}