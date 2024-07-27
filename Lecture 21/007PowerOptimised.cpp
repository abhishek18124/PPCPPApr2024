#include<iostream>

using namespace std;

int f(int x, int y) { // time : O(logy) space : O(logy)

	// base case

	if (y == 0) {
		// find x^0
		return 1;
	}

	// recursive case

	// find x^y

	// 1. ask your friend to find x^(y/2)

	int A = f(x, y / 2);

	if (y % 2 == 0) {
		return A * A;
	}

	return A * A * x;

}

int main() {

	int x = 3;
	int y = 5;

	cout << f(x, y) << endl;

	return 0;
}