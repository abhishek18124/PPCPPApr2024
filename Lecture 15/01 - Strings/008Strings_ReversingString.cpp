#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "abc";
	reverse(s.begin(), s.end());
	cout << s << endl;

	string s2 = "abcdefg";
	reverse(s2.begin() + 2, s2.begin() + 5); // reverses s[2:5)
	cout << s2 << endl;

	return 0;
}