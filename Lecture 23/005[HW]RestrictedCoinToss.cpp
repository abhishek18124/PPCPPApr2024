// n <= 10

#include<iostream>

using namespace std;

void f(int n, char out[], int i) {

	// base case

	if (i == n) {

		out[i] = '\0';
		cout << out << endl;
		return;

	}

	// recursive case

	// decide for the ith coin

	// option 1 : ith coin shows head

	if (i == 0 || out[i - 1] != 'H') {
		out[i] = 'H';
		f(n, out, i + 1);
	}

	// option 2 : ith coin shows tail

	out[i] = 'T';
	f(n, out, i + 1);

}

int main() {

	int n = 3;

	char out[10];

	f(n, out, 0);

	return 0;
}