#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	cout << (void*)&greet << " " << (void*)greet << endl;
	cout << (void*)&add << " " << (void*)add << endl;
	cout << (void*)&ascending << " " << (void*)ascending << endl;


	void (*gptr)() = &greet; // greet;
	int (*aptr)(int, int) = &add; // add;
	bool (*ascptr)(int, int) = &ascending; // ascending;

	cout << (void*) gptr << endl;
	cout << (void*) aptr << endl;
	cout << (void*) ascptr << endl;

	(*greet)();
	greet();
	(*gptr)();
	gptr();

	cout << endl;

	cout << add(2, 3) << endl;
	cout << (*aptr)(2, 3) << endl;
	cout << aptr(2, 3) << endl << endl;

	cout << ascending(5, 6) << endl;
	cout << (*ascptr)(5, 6) << endl;
	cout << ascptr(5, 6) << endl << endl;

	return 0;
}