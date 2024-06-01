#include<iostream>

using namespace std;

int main() {

	int n = 15;
	int cnt = 0; // to track the no. of set bits in 'n'

	while (n > 0) { // #times loops runs = #set bits in n

		cnt++;

		n = n & (n - 1);

	}

	cout << cnt << endl;

	return 0;
}