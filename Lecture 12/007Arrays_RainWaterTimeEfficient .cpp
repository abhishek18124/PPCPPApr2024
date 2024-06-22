// n <= 100

#include<iostream>

using namespace std;

// time = 3n steps ~ O(n)
// space = 2n due l[] and r[] ~ O(n)

int rainwaterOptimised(int h[], int n) {

	int l[100];
	l[0] = h[0];

	for (int i = 1; i < n; i++) { // linear
		l[i] = max(l[i - 1], h[i]);
	}

	int r[100];
	r[n - 1] = h[n - 1];

	for (int i = n - 2; i >= 0; i--) { // linear
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;

	for (int i = 0; i < n; i++) { // linear

		// find the water trapped on top of the ith building

		int wi = min(l[i], r[i]) - h[i];
		total += wi;

	}

	return total;

}

// time = 2n steps ~ O(n)
// space = n due to r[] ~ O(n)

int rainwaterOptimised2(int h[], int n) {

	int r[100];
	r[n - 1] = h[n - 1];

	for (int i = n - 2; i >= 0; i--) { // linear
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;
	int li = 0;// or INT_MIN or h[0]

	for (int i = 0; i < n; i++) { // linear

		// find the water trapped on top of the ith building

		li = max(li, h[i]); // li represents max(0 to i)
		int wi = min(li, r[i]) - h[i];
		total += wi;

	}

	return total;

}

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	cout << rainwaterOptimised(h, n) << endl;
	cout << rainwaterOptimised2(h, n) << endl;

	return 0;
}