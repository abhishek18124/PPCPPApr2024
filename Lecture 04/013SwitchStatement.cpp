#include<iostream>

using namespace std;

int main() {

	int marks;
	cin >> marks;

	char grade;

	if (marks >= 91 && marks <= 100) {
		// cout << "Grade A" << endl;
		grade = 'A';
	} else if (marks >= 81 && marks <= 90) {
		// cout << "Grade B" << endl;
		grade = 'B';
	} else if (marks >= 71 and marks <= 80) {
		// cout << "Grade C" << endl;
		grade = 'C';
	} else if (marks >= 61 and marks <= 70) {
		// cout << "Grade D" << endl;
		grade = 'D';
	} else {
		// cout << "Grade F" << endl;
		grade = 'F';
	}

	// if (grade == 'A') {
	// 	cout << "very good" << endl;
	// } else if (grade == 'B') {
	// 	cout << "good" << endl;
	// } else if (grade == 'C') {
	// 	cout << "bad" << endl;
	// } else if (grade == 'D') {
	// 	cout << "very bad" << endl;
	// } else {
	// 	cout << "fail" << endl;
	// }

	switch (grade) { // int / char can be switched

	case 'A' : cout << "very good" << endl; break;
	case 'B' : cout << "good" << endl; break;
	case 'C' : cout << "bad" << endl; break;
	case 'D' : cout << "very bad" << endl; break;
	default : cout << "fail" << endl; break;

	}

	return 0;
}