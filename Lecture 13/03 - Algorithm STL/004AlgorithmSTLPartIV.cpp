#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	int key = 100;

	// 1. searching for a key in a sequence using find()

	auto it = find(arr, arr + n, key);

	if (it != arr + n) {

		// you've found the key in the given sequence

		cout << key << " found at index " << (it - arr) << endl;

	} else {

		cout << key << " not found" << endl;

	}

	// 2. counting the occurrences of a key in a sequence using count()

	key = 10;

	cout << count(arr, arr + n, key) << endl;

	return 0;
}
