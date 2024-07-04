#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise false

bool comparator(char a, char b) {

	// if (a > b) {
	// 	// we want a to be ordered before b since we are sorting in dec. order
	// 	return true;
	// }

	// return false;

	return a > b;

}

int main() {

	string s = "xacb";
	sort(s.begin(), s.end());
	cout << s << endl;

	// sort(s.rbegin(), s.rend());
	// sort(s.begin(), s.end(), greater<char>());
	sort(s.begin(), s.end(), comparator);
	cout << s << endl;

	return 0;
}