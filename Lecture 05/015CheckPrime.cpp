#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 2;

	while (i <= n - 1) {

		// check if 'i' is a factor of 'n'

		if (n % i == 0) {

			// you've found a factor of 'n' in the range [2, n-1]

			cout << n << " is not prime" << endl;
			break;

		}

		i = i + 1;

	}

	if (i == n) {

		// you did not find any factors of n in the range [2, n-1]

		cout << n << " is a prime" << endl;

	}

	return 0;
}