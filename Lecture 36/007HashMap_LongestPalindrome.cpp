#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int longestPalindromeLength(const string& str) {

	unordered_set<char> us;
	int cnt = 0;

	for (char ch : str) {

		if (us.find(ch) != us.end()) {

			// you've seen ch previouly

			cnt += 2;
			us.erase(ch); // delete the last occ. of ch you've seen since it combines with current ch to form a pair


		} else {

			us.insert(ch);

		}

	}

	if (us.size() > 0) {
		cnt++;
	}

	return cnt;

}

int main() {

	string str = "aabbccccdd";

	cout << longestPalindromeLength(str) << endl;

	return 0;
}