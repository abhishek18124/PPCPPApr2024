// constraints : n <= 100

#include<iostream>

using namespace std;

// int partition(int arr[], int s, int e) {

// 	int pivot = arr[e];

// 	int j = s;
// 	int i = j - 1; // s-1;

// 	while (j <= e - 1) {

// 		if (arr[j] > pivot) {

// 			// put arr[j] in right partition

// 			j++;

// 		} else {

// 			// put arr[j] in left partion

// 			i++;
// 			swap(arr[i], arr[j]);
// 			j++;

// 		}

// 	}


// 	swap(arr[i + 1], arr[e]);

// 	return i + 1;


// }

int partition(int arr[], int s, int e) {

	int pivot = arr[e];

	int j = s;
	int i = j - 1; // s-1;

	while (j <= e - 1) {

		if (arr[j] < pivot) {

			// put arr[j] in left partion

			i++;
			swap(arr[i], arr[j]);

		}

		j++;

	}


	swap(arr[i + 1], arr[e]);

	return i + 1;


}


void quickSort(int arr[], int s, int e) {

	// base case

	if (s > e) {
		return;
	}

	// recursive case

	// 1. partition the arr[s...e] around the pivot i.e. arr[e]

	int pidx = partition(arr, s, e);

	// 2. recursively sort left and right partition i.e. arr[s...pidx-1] and arr[pidx+1...e]

	quickSort(arr, s, pidx - 1);
	quickSort(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}