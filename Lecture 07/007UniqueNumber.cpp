#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cin >> n;

	int x;

	int ans = 0; // to store the unique number

	for (int i = 1; i <= n; i++) {

		cin >> x;

		ans = ans ^ x;

	}

	cout << ans << endl;

	return 0;
}