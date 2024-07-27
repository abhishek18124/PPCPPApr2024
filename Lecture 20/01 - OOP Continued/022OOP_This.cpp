#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer() {
		cout << "\ninside the default constructor of the \'customer\' class\n" << endl;
	}

	customer(string name, int age, char gender, double credits) {
		cout << "\ninside the parameterised constructor of the \'customer\' class\n" << endl;
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}

	void print() {
		cout << "name = " << name << " " << this->name << endl;
		cout << "age = " << age << " " << this->age << endl;
		cout << "gender = " << gender << " " << this->gender << endl;
		cout << "credits = " << credits << " " << this->credits << endl << endl;
	}

};

int main() {

	customer c("Ramanujan", 32, 'M', 1729);
	c.print();

	return 0;
}