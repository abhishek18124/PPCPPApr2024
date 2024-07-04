#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool comparator(int a, int b) {

	string sa = to_string(a);
	string sb = to_string(b);

	if (sa > sb) {

		// we want a to be ordered before b

		return true;

	}

	return false;

}

int main() {

	int arr[] = {98, 9, 78, 7};
	int n = sizeof(arr) / sizeof(int);

	sort(arr, arr + n, comparator);

	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}

	return 0;
}