#include<iostream>

using namespace std;

void greet() {
	cout << "hi" << endl;
	return; // optional
}

int main() {

	cout << "inside main(), before greet()" << endl;

	greet();

	cout << "inside main(), after greet()" << endl;

	return 0;
}