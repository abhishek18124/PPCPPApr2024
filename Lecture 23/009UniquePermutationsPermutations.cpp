#include<iostream>
#include<cstring>

using namespace std;

void f(char inp[], int n, int i) {

	// base case

	if (inp[i] == '\0') {

		cout << inp << endl;
		return;

	}

	// recursive case

	// decide char for the ith index

	for (int j = i; j <= n - 1; j++) {

		// can I use the jth option for the ith index ?

		bool flag = true; // assume you can use the jth option for the ith index

		for (int k = j + 1; k < n; k++) {

			if (inp[k] == inp[j]) {
				flag = false;
				break;
			}

		}

		if (flag) {
			swap(inp[i], inp[j]);
			f(inp, n, i + 1);
			swap(inp[i], inp[j]); // backtracking
		}

	}

}

int main() {

	char inp[] = "aabc";
	int n = strlen(inp);

	f(inp, n, 0);

	return 0;
}
