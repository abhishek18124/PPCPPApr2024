#include<iostream>

using namespace std;

int main() {

	int arr[3][4];

	cout << sizeof(arr) << "B" << endl;

	char brr[2][2];

	cout << sizeof(brr) << "B" << endl;

	double crr[10][5];

	cout << sizeof(crr) << "B" << endl;

	return 0;
}