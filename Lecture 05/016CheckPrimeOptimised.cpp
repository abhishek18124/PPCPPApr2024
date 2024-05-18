#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 2;
	int sq = sqrt(n);

	while (i <= sq) {

		// check if 'i' is a factor of 'n'

		if (n % i == 0) {

			// you've found a factor of 'n' in the range [2, sq]

			cout << n << " is not prime" << endl;
			break;

		}

		i = i + 1;

	}

	if (i > sq) {

		// you did not find any factors of n in the range [2, sq]

		cout << n << " is a prime" << endl;

	}

	return 0;
}