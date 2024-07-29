// constraints : n <= 100

#include<iostream>

using namespace std;

void merge(int arr[], int s, int m, int e) {

	int i = s; // to iterate over arr[s...m]
	int j = m + 1; // to iterate over arr[m+1...e]
	int k = s; // to iterate over temp[s...e]

	int temp[100]; // based on constraints

	while (i <= m and j <= e) {

		if (arr[i] < arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		} else {
			temp[k] = arr[j];
			j++;
			k++;
		}

	}

	while (i <= m) {

		temp[k] = arr[i];
		i++;
		k++;

	}

	while (j <= e) {

		temp[k] = arr[j];
		j++;
		k++;

	}

	for (int l = s; l <= e; l++) {
		arr[l] = temp[l];
	}

}

void mergeSort(int arr[], int s, int e) {

	// base case

	if (s == e) {
		return;
	}

	// recursive case

	// 1. divide the arr[s...e] around the midPoint

	int m = s + (e - s ) / 2;

	// 2. recursively sort arr[s...m] and arr[m+1...e]

	mergeSort(arr, s, m);
	mergeSort(arr, m + 1, e);

	// 3. merge the two sorted subarray such that the merged arr[] is sorted

	merge(arr, s, m, e);

}

int main() {

	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}