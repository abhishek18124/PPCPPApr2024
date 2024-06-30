// n <= 100

#include<iostream>

using namespace std;

void readString(char str[], char delimiter = '\n') {

	char ch;
	int i = 0;

	while (true) {

		ch = cin.get();
		if (ch == delimiter) { // delimiting character
			break;
		}

		str[i] = ch;
		i++;

	}

	str[i] = '\0';

}

int main() {

	char str[101];

	// cin >> str; // '\0' is added automatically to the input string

	// readString(str, '$');

	cin.getline(str, 5, '$');

	cout << str << endl;

	return 0;
}