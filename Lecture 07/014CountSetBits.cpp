#include<iostream>
#include<cmath>
#include<bitset>

using namespace std;

int main() {

	int n = 15;
	int cnt = 0; // to track the no. of set bits in 'n'

	cout << bitset<8>(n) << endl;

	for (int k = 0; k <= 31; k++) {

		// check if the kth bit of n is set or not

		if ((n >> k) & 1) {
			cnt++;
		}

	}

	cout << cnt << endl;

	return 0;
}