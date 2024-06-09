#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int& y = x; // y is a reference variable which refers to x i.e. it is a new name for x

	y++;

	cout << x << " " << y << endl;

	return 0;
}