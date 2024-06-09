#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false; // n is not prime
		}
	}

	return true; // n is prime

}

void printPrimes(int m) {

	for (int n = 2; n <= m; n++) {

		// check if n is prime

		if (isPrime(n)) {

			// n is a prime number

			cout << n << " ";

		}

	}

}

int main() {

	int m;
	cin >> m;

	printPrimes(m);

	return 0;
}