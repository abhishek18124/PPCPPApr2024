#include<iostream>

using namespace std;

bool isEven(int x) {
	return x % 2 == 0;
}

int main() {

	bool ans = isEven(4);

	cout << ans << endl;

	cout << isEven(5) << endl;

	// if a fn call returns a value, you can treat that fn call as an expr

	if (isEven(7)) {
		cout << 7 << " is even" << endl;
	} else {
		cout << 7 << " is odd" << endl;
	}

	isEven(8) ? cout << "8 is even" << endl : cout << "8 is odd" << endl;

	return 0;
}