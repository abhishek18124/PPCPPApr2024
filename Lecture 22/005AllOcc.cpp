#include<iostream>

using namespace std;

bool flag = false; // assume t is not present in X[]

void f(int X[], int n, int t, int i) {

	// base case
	if (i == n) {
		return;
	}

	// recursive case

	if (X[i] == t) {
		flag = true;
		cout << i << " ";
	}

	f(X, n, t, i + 1);

}

int main() {

	int X[] = {10, 20, 30, 20, 30};
	int n = sizeof(X) / sizeof(int);
	int t = 100;

	f(X, n, t, 0);

	if (flag == false) {
		cout << -1;
	}

	return 0;
}