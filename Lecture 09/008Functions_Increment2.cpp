#include<iostream>

using namespace std;

void inc(int& ref) {
	ref++;
}

int main() {

	int a = 0;

	cout << "main() before inc() a = " << a << endl;

	inc(a);

	cout << "main() after inc() a = " << a << endl;

	return 0;
}