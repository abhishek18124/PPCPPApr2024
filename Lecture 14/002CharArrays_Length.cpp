#include<iostream>
#include<cstring>

using namespace std;

int computeLength(char str[]) {

	int cnt = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		cnt++;
	}

	return cnt;

}

int main() {

	// char str[100];
	// cin.getline(str, 100);

	char str[] = "coding";

	cout << computeLength(str) << endl;
	cout << strlen(str) << endl;

	return 0;
}