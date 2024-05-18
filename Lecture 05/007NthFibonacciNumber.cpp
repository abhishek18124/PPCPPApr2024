#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0  || n == 1) {

		cout << n << endl;

	} else {

		// n >= 2

		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.

		int i = 2;

		// (n-1).c ~ nc. ~ O(n)

		while (i <= n) {

			// find the ith fib. no.

			int c = a + b;
			a = b;
			b = c;

			i = i + 1;
		}

		// cout << c << endl; // error since c is not in scope
		cout << b <<  endl; // b contains the value of c

	}

	return 0;
}