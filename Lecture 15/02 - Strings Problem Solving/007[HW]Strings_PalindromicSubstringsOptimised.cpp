#include<iostream>
#include<string>

using namespace std;

int countPalindromicSubstrings(string s) {

	int n = s.size();

	int cnt = 0; // to track the no. of palindromic substrings in the given string

	// 1. count the no. of odd-length palindromic substrings

	for (int i = 0; i < n; i++) {

		// count the no. of odd-length palindromic substrings around s[i]

		int j = 0;
		// int localcnt = 0;

		while (i - j >= 0 and i + j <= n - 1 and s[i - j] == s[i + j]) {

			cnt++;
			// localcnt++;
			j++;

		}

		// cout << localcnt << endl;

	}

	// 2. count the no. of even-length palindromic substrings

	for (double i = 0.5; i < n; i++) {

		// count the no. of odd-length palindromic substrings around s[i]

		double j = 0.5;

		while (i - j >= 0 and i + j <= n - 1 and s[int(i - j)] == s[int(i + j)]) {

			cnt++;
			j++;

		}

	}

	return cnt;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	return 0;
}