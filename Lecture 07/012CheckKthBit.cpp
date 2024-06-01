#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 4;

	if ((n & (1 << k)) == 0) {
		cout << k << "th bit of " << n << " is not set" << endl;
	} else {
		cout << k << "th bit of " << n << " is set" << endl;
	}

	if (((n >> k) & 1) == 1) {
		cout << k << "th bit of " << n << " is set" << endl;
	} else {
		cout << k << "th bit of " << n << " is not set" << endl;
	}

	return 0;
}