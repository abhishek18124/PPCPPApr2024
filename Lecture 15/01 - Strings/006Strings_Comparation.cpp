#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	string s2 = "def";

	cout << s1.compare(s2) << endl;
	cout << s2.compare(s1) << endl;

	string s3 = "xyz";
	string s4 = "xyz";
	cout << s3.compare(s4) << endl;

	string s5 = "abc";
	string s6 = "adc";

	if (s5 > s6) {

		cout << s5 << " > " << s6 << endl;

	} else {

		cout << s6 << " > " << s5 << endl;

	}

	return 0;
}