#include<iostream>

using namespace std;

void bubbleSort(int arr[], int n) {

	// iterate over the n-1 passes of the bubbleSort algorithm

	int cnt = 0;

	for (int i = 1; i <= n - 1; i++) {

		// for the ith pass, place the largest element in the unsorted part of the arr[] to its correct position

		bool flag = false; // assume no swaps be will done in the ith pass

		for (int j = 0; j < n - i; j++) {

			cnt++;

			if (arr[j] > arr[j + 1]) {

				swap(arr[j], arr[j + 1]);
				flag = true;

			}

		}

		if (flag == false) {
			break;
		}

	}

	cout << cnt << endl;

}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	bubbleSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}