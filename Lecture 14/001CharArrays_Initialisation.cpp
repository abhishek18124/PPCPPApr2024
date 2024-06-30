#include<iostream>

using namespace std;

int main() {

	char str[] = {'a', 'b', 'c', 'd', 'e', '\0'};

	cout << str << endl;

	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i] << " ";
	}

	cout << endl;

	char str2[] = "hello";

	for (int i = 0; str2[i] != '\0'; i++) {
		cout << str2[i] << " ";
	}

	cout << endl;

	char str3[10] = "world";

	cout << str3 << endl;

	return 0;
}