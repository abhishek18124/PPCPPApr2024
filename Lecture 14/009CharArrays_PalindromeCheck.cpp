#include<iostream>
#include<cstring>

using namespace std;

bool isPalindrome(char s[]) {

	int i = 0;
	int j = strlen(s) - 1;

	while (i < j) {

		if (s[i] != s[j]) {

			// s[] is not a palindrome

			return false;

		}

		i++;
		j--;

	}

	// s[] is a palindrome

	return true;

}

int main() {

	char str[] = "abcdeexcba";

	isPalindrome(str) ? cout << "palindrome" << endl : cout << "not a palindrome" << endl;

	return 0;
}