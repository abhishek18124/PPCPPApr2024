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

int main() {

	int n;
	cin >> n;

	isPrime(n) ? cout << n << " is prime" << endl :
	                  cout << n << " is not prime" << endl;

	return 0;
}