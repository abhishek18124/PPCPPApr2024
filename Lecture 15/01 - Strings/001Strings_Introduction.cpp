#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1;
	s1 = "hello";
	cout << s1 << endl;

	string s2 = "hi";
	cout << s2 << endl;

	string s3 = "india";
	for (int i = 0; s3[i] != '\0'; i++) {
		cout << "s3[" << i << "] = " << s3[i] << endl;
	}
	cout << endl;

	return 0;
}