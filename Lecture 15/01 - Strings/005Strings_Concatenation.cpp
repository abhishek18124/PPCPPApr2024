#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	string s2 = "de";

	cout << s1 + s2 << endl;
	cout << s1 << endl;
	cout << s2 << endl << endl;

	s1 = s1 + s2;
	cout << s1 << endl;
	cout << s2 << endl << endl;

	s1.push_back('f');
	cout << s1 << endl;

	s1.pop_back();
	cout << s1 << endl;

	cout << s1[0] << " " << s1.front() << endl;

	int n = s1.size();
	cout << s1[n - 1] << " " << s1.back() << endl;

	string s3 = "xyz";

	s3 = s3 + string(1, 'a');
	cout << s3 << endl;

	s3 = string(1, 'b') + s3;
	cout << s3 << endl;


	return 0;
}