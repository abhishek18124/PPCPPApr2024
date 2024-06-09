#include<iostream>

using namespace std;

void isEven(int x) {

	if (x % 2 == 0) {
		cout << x << " is even " << endl;
	} else {
		cout << x << " is odd" << endl;
	}

}

int main() {

	isEven(4);

	isEven(5);

	return 0;
}