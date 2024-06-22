#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

// time : O(n^2)

int maxArea(int h[], int n) {

	int maxSoFar = INT_MIN;

	for (int i = 0; i <= n - 2; i++) {

		for (int j = i + 1; j <= n - 1; j++) {

			// find the area using the ith and jth line

			// int width_ij = j-i;
			// int height_ij = min(h[i], h[j]);
			// int area_ij = width_ij * height_ij;
			// maxSoFar = max(maxSoFar, area_ij);

			maxSoFar = max(maxSoFar, min(h[i], h[j]) * (j - i)); // const

		}

	}

	return maxSoFar;

}

// time : O(n)

int maxAreaOptimised(int h[], int n) {

	int i = 0;
	int j = n - 1;

	int maxSoFar = INT_MIN;

	while (i < j) {

		// find the area using the ith and jth line

		maxSoFar = max(maxSoFar, (j - i) * min(h[i], h[j]));

		if (h[i] < h[j]) {

			i++;

		} else {

			j--;

		}

	}

	return maxSoFar;

}

int main() {

	int h[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int n = sizeof(h) / sizeof(int);

	cout << maxArea(h, n) << endl;

	cout << maxAreaOptimised(h, n) << endl;

	return 0;
}