#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};

	cout << "sizeof(A) = " << sizeof(A) << "B" << endl;

	cout << "A[0] = " << A[0] << endl;
	cout << "A[1] = " << A[1] << endl;
	cout << "A[2] = " << A[2] << endl;
	cout << "A[3] = " << A[3] << endl;
	cout << "A[4] = " << A[4] << endl << endl;

	int B[] = {100, 200, 300};

	cout << "sizeof(B) = " << sizeof(B) << "B" << endl;

	cout << "B[0] = " << B[0] << endl;
	cout << "B[1] = " << B[1] << endl;
	cout << "B[2] = " << B[2] << endl << endl;

	int n = sizeof(B) / sizeof(int);

	cout << n << endl;


	int C[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000};

	int m = sizeof(C) / sizeof(int);

	cout << m << endl;

	for (int i = 0; i <= m - 1; i++) {
		cout << "C[" << i << "] = " << C[i] << endl;
	}

	cout << endl;

	for (int i = m - 1; i >= 0; i--) {
		cout << "C[" << i << "] = " << C[i] << endl;
	}

	int D[5] = {10, 20, 30};

	for (int i = 0; i < 5; i++) {
		cout << D[i] << " ";
	}

	cout << endl;

	int E[10] = {};

	for (int i = 0; i < 10; i++) {
		cout << E[i] << " " ;
	}

	cout << endl;

	int F[10] = {0};

	for (int i = 0; i < 10; i++) {
		cout << F[i] << " " ;
	}

	cout << endl;

	int G[5];

	memset(G, 0, sizeof(G));

	for (int i = 0; i < 5; i++) {
		cout << G[i] << " ";
	}

	cout << endl;

	return 0;
}