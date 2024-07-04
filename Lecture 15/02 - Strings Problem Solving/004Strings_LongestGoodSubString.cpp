#include<iostream>
#include<string>

using namespace std;

bool isGoodString(string str) { // linear

	for (char ch : str) {

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {

			// ch is consonant, therefore str is not good

			return false;

		}

	}

	// str is good

	return true;

}

// time : n^2.n ~ O(n^3)

int longestGoodSubstring(string str) {

	int maxSoFar = 0;

	int n = str.size();

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			string subString = str.substr(i, j - i + 1);

			if (isGoodString(subString)) {

				maxSoFar = max(maxSoFar, j - i + 1);

			}

		}

	}

	return maxSoFar;

}

int main() {

	string str = "cbaeicdeiou";

	cout << longestGoodSubstring(str) << endl;

	return 0;
}