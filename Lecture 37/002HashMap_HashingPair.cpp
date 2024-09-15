#include<iostream>
#include<unordered_map>

using namespace std;

class PairHash {

public:

	size_t operator()(pair<string, int> p) const {

		// hash<string> stringHash;
		// size_t nameHash = stringHash(p.first);

		// hash<int> integerHash;
		// size_t ageHash = integerHash(p.second);

		// return nameHash ^ ageHash;

		return hash<string>()(p.first) ^ hash<int>()(p.second);

	}

};

int main() {

	unordered_map<pair<string, int>, double, PairHash> ratingMap;

	ratingMap[ {"Ayush", 19}] = 3.5;
	ratingMap[ {"Anant", 18}] = 4.5;
	ratingMap[ {"Nameesha", 20}] = 3.7;
	ratingMap[ {"Manan", 21}] = 4.5;

	for (pair<pair<string, int>, double> p : ratingMap) {
		pair<string, int> c = p.first;
		double r = p.second;
		cout << c.first << " " << c.second << " " << r << endl;
	}

	cout << endl;

	ratingMap[ {"Ayush", 19}] = 4.9;

	for (pair<pair<string, int>, double> p : ratingMap) {
		pair<string, int> c = p.first;
		double r = p.second;
		cout << c.first << " " << c.second << " " << r << endl;
	}

	cout << endl;

	return 0;
}