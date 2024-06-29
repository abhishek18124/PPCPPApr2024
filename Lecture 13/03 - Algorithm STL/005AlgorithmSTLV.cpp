#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {10, 10, 20, 30, 30, 30, 30, 30, 40, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	// arr[] should sorted to use the following functions

	int key = 100;

	// 1. searching for a key in a sorted sequence in O(logn) using binary_search()

	binary_search(arr, arr + n, key) ? cout << "true" << endl : cout << "false" << endl;

	// 2. finding lower bound for a key in a sorted sequence in O(logn) using lower_bound()

	key = 30;

	cout << lower_bound(arr, arr + n, key) - arr << endl;

	// 3. finding upper bound for a key in a sorted sequence in O(logn) using upper_bound()

	cout << upper_bound(arr, arr + n, key) - arr << endl;

	// 4. counting the occurences of a key in a sorted sequence in O(logn)

	cout << upper_bound(arr, arr + n, key) - lower_bound(arr, arr + n, key) << endl;

	return 0;
}