#include<iostream>
#include<cmath>
#include<bitset>

using namespace std;

int main() {

	int n = 22;
	int cnt = 0; // to track the no. of set bits in 'n'

	cout << bitset<8>(n) << endl;

	// approach - 1

	// for (int k = 0; k < ceil(log2(n + 1)); k++) { // logn steps

	// 	// check if the kth bit of n is set or not

	// 	if ((n >> k) & 1) {
	// 		cnt++;
	// 	}

	// }

	// approach - 2

	while (n > 0) { // logn steps

		int rightmostBit = n & 1;

		if (rightmostBit) {
			cnt++;
		}

		n = n >> 1;

	}

	cout << cnt << endl;


	return 0;
}