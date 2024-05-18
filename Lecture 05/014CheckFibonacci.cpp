#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 || n == 1) {

		cout << "true" << endl; // 0 and 1 are part the fibonacci sequence

	} else {

		int a = 0; // 0th fibo. no.
		int b = 1; // 1st fibo. no.

		while (true) {

			int c = a + b;

			if (c == n) {

				cout << "true" << endl;
				break;

			}

			if (c > n) {

				cout << "false" << endl;
				break;

			}

			// c < n

			a = b;
			b = c;
		}

	}

	return 0;
}