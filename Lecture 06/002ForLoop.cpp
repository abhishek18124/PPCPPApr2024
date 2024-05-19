#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// for (int i = 0; i < n; i++) {
	// 	cout << i << " ";
	// }

	// cout << endl;

	// for (int i = 0, j = n; i < j; i++, j--) {
	// 	cout << i << " " << j << endl;
	// }

	// int i;
	// for (i = 0; i < n; i++) {
	// 	cout << i << " ";
	// }
	// cout << endl << "i = " << i << endl;

	int i = 0;
	for (; i < n; i++) {
		cout << i << " ";
	}
	cout << endl << "i = " << i << endl;


	return 0;
}