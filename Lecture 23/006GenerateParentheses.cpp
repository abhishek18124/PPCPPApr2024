// n <= 8

#include<iostream>

using namespace std;

void f(int n, char out[], int i, int openCnt, int closeCnt) {

	// base case

	if (i == 2 * n) { // openCnt == n and closeCnt == n

		out[i] = '\0';
		cout << out << endl;
		return;

	}

	// recursive case

	// decide the ith char

	// option 1 : use '('

	if (openCnt < n) {

		out[i] = '(';
		f(n, out, i + 1, openCnt + 1, closeCnt);

	}

	// option 2 : use ')'

	if (closeCnt < n) {

		out[i] = ')';
		f(n, out, i + 1, openCnt, closeCnt + 1);

	}

}

int main() {

	int n = 2;

	char out[17]; // based on contraints

	f(n, out, 0, 0, 0);

	return 0;
}