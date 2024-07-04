#include<iostream>
#include<string>

using namespace std;

void generateSubstrings(string str, int n) {

	for (int l = 1; l <= n; l++) {

		// print all the substrings of length l

		for (int i = 0; i <= n - l; i++) {

			// print the substring that starts at the ith index has length l

			cout << str.substr(i, l) << endl;

		}

		cout << endl;

	}

	cout << endl;

}

int main() {

	string str = "abcde";
	int n = str.size();

	generateSubstrings(str, n);

	return 0;
}