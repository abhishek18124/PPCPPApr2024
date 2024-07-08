#include<iostream>

using namespace std;

int main() {

	int* ptr = new int;

	*ptr = 50;

	cout << *ptr << endl;

	delete ptr; // to avoid memeory-leak

	ptr = new int;

	char* chptr = new char;

	*chptr = 'A';

	cout << *chptr << endl;

	double* dptr = new double;

	*dptr = 3.14;

	cout << *dptr << endl;

	return 0;
}