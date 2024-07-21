#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}
};

// return true if you want a to be ordered before b otherwise return false

bool comparator(customer a, customer b) {

	if (a.age < b.age) {

		return true; // since we sorting in inc. order based on customer age

	}

	return false;

}

class Comparator {
public:
	bool operator()(customer a, customer b) {
		if (a.age < b.age) {

			return true; // since we sorting in inc. order based on customer age

		}

		return false;
	}
};

int main() {

	vector<customer> v;

	v.push_back(customer("Ramanujan", 32, 'M', 1729));
	v.push_back(customer("JC Bose", 78, 'M', 2500));
	v.push_back(customer("Aryabhata", 74, 'M', 0));
	v.push_back(customer("Vikram", 52, 'M', 1500));
	v.push_back(customer("Homi", 56, 'M', 1000));

	// sort(v.begin(), v.end(), comparator);

	Comparator obj;
	sort(v.begin(), v.end(), obj);

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	return 0;
}