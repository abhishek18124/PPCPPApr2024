#include<iostream>
#include<unordered_map>
#include<functional>

using namespace std;

class customer {

public :

	string name;
	int age;

	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}

	bool operator==(customer other) const {
		return this->name == other.name and this->age == other.age;
	}

};

class customerHash {

public:

	size_t operator()(customer c) const {

		hash<string> stringHash; // callable
		size_t nameHash = stringHash(c.name);

		hash<int> integerHash; // callable
		size_t ageHash = integerHash(c.age);

		return nameHash ^ ageHash;

	}

};

int main() {

	unordered_map<customer, double, customerHash> ratingMap;

	// customer c1("Ayush", 19);
	// ratingMap[c1] = 3.5;

	ratingMap[customer("Ayush", 19)] = 3.5;
	ratingMap[customer("Anant", 18)] = 4.5;
	ratingMap[customer("Nameesha", 20)] = 3.7;
	ratingMap[customer("Manan", 21)] = 4.5;

	for (pair<customer, double> p : ratingMap) {
		customer c = p.first;
		double r = p.second;
		cout << c.name << " " << c.age << " " << r << endl;
	}

	cout << endl;

	ratingMap[customer("Ayush", 19)] = 4.9;

	for (pair<customer, double> p : ratingMap) {
		customer c = p.first;
		double r = p.second;
		cout << c.name << " " << c.age << " " << r << endl;
	}

	cout << endl;


	return 0;
}