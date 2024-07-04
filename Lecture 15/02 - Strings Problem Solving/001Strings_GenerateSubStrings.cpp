#include<iostream>
#include<string>

using namespace std;

void generateSubstrings(string str, int n) {

	// iterate over all the possible starting indices of str

	for (int i = 0; i <= n - 1; i++) {

		// for given i, iterate over all the possible ending indices of str

		for (int j = i; j <= n - 1; j++) {

			// generate the substring that starts at the ith index and ends at the jth index

			// for (int k = i; k <= j; k++) {

			// 	cout << str[k];

			// }

			// cout << endl;

			cout << str.substr(i, j - i + 1) << endl;

		}

		cout << endl;

	}

}

int main() {

	string str = "abcde";
	int n = str.size();

	generateSubstrings(str, n);

	return 0;
}