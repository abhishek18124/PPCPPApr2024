/*

Given a string of length n, generate all of its subsequences.

A subsequence of a given string (sequence) is a string (sequence) that is generated by
removing zero or more characters from the given string (sequence) without changing its
order.

Example

	Input : inp[] = "abc"
	Output: ["", "c", "b", "bc", "a", "ac", "ab", "abc"]

Constraints

  1 < n < 10

*/

#include<iostream>
#include<set>

using namespace std;

set<string> s;

void f(char inp[], char out[], int i, int j) {

	// base case

	if (inp[i] == '\0') { // i == n

		out[j] = '\0';
		// cout << out << endl;

		// string outString(out);
		// s.insert(outString);

		s.insert(string(out));

		return;

	}

	// recursive case

	// f(i) : it is a fn that takes a seq. of n-i decisions for char i to n-1

	// f(i) : it is a fn that generate subseq. for inp[i...n-1]

	// take decision for inp[i]

	// option 1 : include inp[i] to out[]

	out[j] = inp[i];
	f(inp, out, i + 1, j + 1);

	// option 2 : exclude inp[i] from out[]

	f(inp, out, i + 1, j);

}

int main() {

	char inp[] = "abc";
	char out[10];

	f(inp, out, 0, 0);

	for (string subseq : s) {
		cout << subseq << endl;
	}

	cout << endl;

	return 0;
}
