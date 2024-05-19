#include<iostream>

using namespace std;

int main() {

	char ch = 'B';

	cout << ch << endl;
	cout << (int)ch << endl;

	ch = 'A';

	cout << ch << endl;
	cout << (int)ch << endl;

	ch = 'c';

	cout << ch << endl;
	cout << (int)ch << endl;

	ch = '5';
	cout << ch << endl;
	cout << (int)ch << endl;

	ch = '7';
	int x = ch - '0';
	cout << x << endl;
	cout << ch - '0' << endl;

	ch = '5';
	int y = (int)ch;
	cout << y << endl;


	return 0;
}