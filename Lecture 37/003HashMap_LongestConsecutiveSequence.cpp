/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

	// time : O(n)
	// space: O(n) due to startMap

	int longestConsecutive(vector<int>& nums) {

		unordered_map<int, bool> startMap;

		for (int i = 0; i < nums.size(); i++) { // linear (n-steps)

			if (startMap.find(nums[i] - 1) == startMap.end()) {

				//  you've not seen nums[i] - 1 so far

				startMap[nums[i]] = true;

			} else {

				// nums[i] cannot a starting point of a sequence of consecutive elements

				startMap[nums[i]] = false;

			}

			if (startMap.find(nums[i] + 1) != startMap.end()) {

				// you've seen nums[i] + 1 previously

				startMap[nums[i] + 1] = false;

			}

		}

		// for (pair<int, bool> p : startMap) {
		// 	int el = p.first;
		// 	bool canStart = p.second;
		// 	cout << el << " " << canStart << endl;
		// }

		int maxSofar = 0;

		for (pair<int, bool> p : startMap) { // linear (n-steps)

			int key = p.first;
			bool canStart = p.second;

			if (canStart) {

				// you can start a sequence of consecutive elements from key

				int cnt = 0;
				while (startMap.find(key) != startMap.end()) {
					cnt++;
					key++;
				}

				// cout << cnt << endl;

				maxSofar = max(maxSofar, cnt);

			}

		}

		return maxSofar;

	}
};

int main() {

	Solution s;

	vector<int> nums = {0, 1, 4, 5, 6, 11, 12, 13, 14};

	cout << s.longestConsecutive(nums) << endl;

}
