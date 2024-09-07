/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {
public:
	string name;
	int age;
	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

class ageComparator {

public:

	// // return true if you want a to be ordered before b otherwise return false

	// bool operator()(customer a, customer b) {

	// 	if (a.age < b.age) {

	// 		// we want a to be ordered before b since we are building a minHeap based on age

	// 		return true;

	// 	}

	// 	return false;

	// }

	// return false if you want a to be given more priority than b otherwise return true

	bool operator()(customer a, customer b) {

		if (a.age < b.age) {

			// we want a to be given more priority than b since we are building a minHeap based on age

			return false;

		}

		return true;;

	}

};

class nameComparator {

public:

	// return false if you want a to be given more priority than b otherwise return true

	bool operator()(customer a, customer b) {

		if (a.name > b.name) {

			// we want a to be given more priority than b since we are building a maxHeap based on name

			return false;

		}

		return true;;

	}

};

int main() {

	// priority_queue<customer, vector<customer>, ageComparator> m; // we are building a minHeap based on customer age
	priority_queue<customer, vector<customer>, nameComparator> m; // we are building a minHeap based on customer age

	m.push(customer("lakshay", 22));
	m.push(customer("shashank", 20));
	m.push(customer("khushi", 19));
	m.push(customer("manan", 18));
	m.push(customer("tushar", 21));

	cout << m.size() << endl;  // 5

	while (!m.empty()) {
		customer c = m.top();
		cout << c.name << " " << c.age << endl;
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl; // 0

	return 0;
}