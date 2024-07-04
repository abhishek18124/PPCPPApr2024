#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool lengthComparator(string a, string b) {

	if (a.size() < b.size()) {

		// we want a to be ordered before b since we are sorting in inc. order based on length

		return true;

	}

	return false;

}

int main() {

	string arr[] = {"xy", "gh", "abcd", "e"};

	int n = 4;

	// sort(arr, arr + n); // by defaults sort arr[] in lexicographically inc. order

	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	sort(arr, arr + n, lengthComparator);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}