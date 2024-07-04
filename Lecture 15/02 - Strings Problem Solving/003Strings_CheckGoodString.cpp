#include<iostream>
#include<string>

using namespace std;

bool isGoodString(string str) {

	// for (int i = 0; i < str.size(); i++) {

	// 	char ch = str[i];

	// 	if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {

	// 		// ch is consonant, therefore str is not good

	// 		return false;

	// 	}

	// }

	for (char ch : str) {

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {

			// ch is consonant, therefore str is not good

			return false;

		}

	}

	// str is good

	return true;

}

int main() {

	string str = "uoiea";

	isGoodString(str) ? cout << "good" << endl : cout << "not good" << endl;


	return 0;
}