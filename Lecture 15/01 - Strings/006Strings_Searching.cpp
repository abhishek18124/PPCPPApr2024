#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdefdeg";

	cout << s.find("de") << endl;
	cout << s.rfind("de") << endl;
	cout << s.find("xyz") << endl;
	cout << string::npos << endl;

	if (s.find("xyz") != string::npos) {
		cout << "xyz is present in s" << endl;
	} else {
		cout << "xyz is not present in s" << endl;
	}

	return 0;
}