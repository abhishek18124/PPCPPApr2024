#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> f(int A[], int n) {

	stack<pair<int, int>> s; // <value, index>
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		// find the index of the nearest smaller element to the right of A[i]

		while (!s.empty() and s.top().first >= A[i]) {
			s.pop();
		}

		if (s.empty()) {

			// A[i] doesn't have any smaller elements to its right

			ans.push_back(n);

		} else {

			ans.push_back(s.top().second);

		}

		s.push({A[i], i});

	}

	reverse(ans.begin(), ans.end());

	return ans;

}

vector<int> f2(int A[], int n) {

	stack<int> s; // <index>
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		// find the index of the nearest smaller element to the right of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {

			// A[i] doesn't have any smaller elements to its right

			ans.push_back(n);

		} else {

			ans.push_back(s.top());

		}

		s.push(i);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}


int main() {

	int A[] = {2, 5, 1, 3, 6, 4, 0};
	int n = sizeof(A) / sizeof(int);

	vector<int> ans = f(A, n);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	ans = f2(A, n);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}