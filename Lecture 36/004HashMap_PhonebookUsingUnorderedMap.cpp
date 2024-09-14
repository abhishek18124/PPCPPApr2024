/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phoneMap;
	phoneMap["Manan"].push_back("0000");
	phoneMap["Manan"].push_back("1111");
	phoneMap["Khushi"].push_back("2222");
	phoneMap["Vanshika"].push_back("3333");
	phoneMap["Vanshika"].push_back("4444");

	for (pair<string, vector<string>> p : phoneMap) {

		string name = p.first;
		vector<string> nums = p.second;

		cout << name << " : ";
		for (string num : nums) {
			cout << num << " ";
		}
		cout << endl;

	}

	return 0;
}