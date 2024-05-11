#include<iostream>

using namespace std;

int main() {

	int p;
	cin >> p;

	int r;
	cin >> r;

	int t;
	cin >> t;

	cout << p * r * t / 100 << endl;
	cout << (p * r * t) / 100 << endl; // more readable
	cout << (float)(p * r * t) / 100 << endl; // more readable
	cout << float(p * r * t / 100) << endl; //


	cout << p * r * t / 100.0 << endl;
	cout << p * r * t * 1.0 / 100 << endl;
	cout << (float)p * r * t / 100  << endl;
	cout << static_cast<float>(p) * r * t / 100 << endl;

	float si = (p * r * t) / 100;
	cout << si << endl;

	float newsi = (p  * r * t) / 100.0;
	cout << newsi << endl;

	return 0;
}