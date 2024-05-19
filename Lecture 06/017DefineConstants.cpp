#include<iostream>
#define PI 3.14
#define PRINT cout <<
#define SEMICOLON ;
#define NEWLINE endl
#define F5 for (int i = 0; i < 5; i++) {cout << i << " ";}
#define F(n) for (int i = 0; i < n; i++) {cout << i << " ";}
#define ll long long


using namespace std;

int main() {

	PRINT PI << NEWLINE SEMICOLON

	         // F5

	         int n;
	cin >> n;

	F(n);

	return 0;
}