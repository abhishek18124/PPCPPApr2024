#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

// time : O(n) worst case e.g. 5 4 3 2 1 (2n-1 ops => n push,n-1 pops)
// space: O(n) worst case e.g. 1 2 3 4 5 (n push therefore time is O(n) and linear space due to stack)

vector<int> f(int A[], int n) {

	stack<int> s;
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {

			// A[i] doesn't have any greater elements to its right

			ans.push_back(-1);

		} else {

			ans.push_back(s.top());

		}

		s.push(A[i]);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	int A[] = {5, 3, 6, 7, 2, 1, 4};
	int n = sizeof(A) / sizeof(int);

	vector<int> ans = f(A, n);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}