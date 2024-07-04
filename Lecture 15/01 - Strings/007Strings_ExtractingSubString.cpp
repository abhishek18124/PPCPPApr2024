#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdef";

	cout << s.substr(1, 4) << endl;
	cout << s.substr(1) << endl;
	cout << s.substr(3, 10) << endl;

	return 0;
}