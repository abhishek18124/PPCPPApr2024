#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "cbaeicdeiou";

	// time : n.c ~ O(n)

	int cnt = 0; // to track the length of the longest good substring
	int maxSoFar = 0;

	for (char ch : str) {

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {

			// ch is vowel

			cnt++;
			maxSoFar = max(maxSoFar, cnt);

		} else {

			// ch is consonant

			cnt = 0;

		}

	}

	cout << maxSoFar << endl;

	return 0;
}