#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 20;

	int cnt = 0;
	bool flag = false; // assume t is not present in the arr[]

	for (int i = 0; i < n; i++) {

		if (arr[i] == t) {

			cout << i << " ";
			cnt++;
			flag = true;

		}

	}

	if (cnt == 0) {
		cout << t << " not found" << endl;
	}

	if (flag == false) {
		cout << t << " not found" << endl;
	}

	return 0;
}