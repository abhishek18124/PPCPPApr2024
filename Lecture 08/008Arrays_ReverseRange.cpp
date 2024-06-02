#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int i;
	int j;

	cin >> i >> j;

	while (i < j) { // n/2 swaps.const ~ O(n)

		swap(arr[i], arr[j]);
		i++;
		j--;

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}