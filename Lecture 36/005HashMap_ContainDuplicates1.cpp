#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

// time : on avg. O(n)
// space : O(n) if all elements are unique

bool isDuplicatePresent(const vector<int>& v) {

	unordered_map<int, int> freqMap;
	for (int i = 0; i < v.size(); i++) {
		freqMap[v[i]]++;
		if (freqMap[v[i]] > 1) {
			return true; // v[i] is a duplicate
		}
	}

	for (pair<int, int> p : freqMap) {
		int el = p.first;
		int freq = p.second;
		cout << el << " " << freq << endl;
	}

	return false; // no duplicates found


}

// time : on avg. O(n)
// space : O(n) if all elements are unique

bool isDuplicatePresent2(const vector<int>& v) {

	unordered_set<int> us;
	for (int i = 0; i < v.size(); i++) {
		if (us.find(v[i]) == us.end()) {
			// v[i] is not seen so far
			us.insert(v[i]);
		} else {
			// v[i] was seen previously
			// v[i] is a duplicate
			return true;
		}
	}

	return false; // no duplicates found


}

int main() {

	vector<int> v = {1, 2, 3, 3};

	isDuplicatePresent(v) ? cout << "true" << endl : cout << "false" << endl;
	isDuplicatePresent2(v) ? cout << "true" << endl : cout << "false" << endl;


	return 0;
}