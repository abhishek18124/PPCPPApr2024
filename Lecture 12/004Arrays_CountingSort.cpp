// contraints : n <= 100, k <= 9

#include<iostream>

using namespace std;

int main() {

	// time : 2n steps ~ O(n)
	// space: k+1 ~ O(k) due to freq[]

	int arr[] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
	int n = sizeof(arr) / sizeof(int);

	int k = 3; // denotes the maximum element in the array

	int freq[10] = {0}; // based on constraints

	// memset(freq, 0, sizeof(freq));

	for (int i = 0; i < n; i++) { // n-steps

		// int x = arr[i];
		// freq[x]++;

		freq[arr[i]]++;

	}

	for (int i = 0; i <= k; i++) {

		cout << "freq(" << i << ") = " << freq[i] <<  endl;

	}

	for (int i = 0; i <= k; i++) { // n-steps

		int j = freq[i];

		// print 'i' j times

		while (j--) {
			cout << i << " ";
		}

	}

	return 0;
}