#include<iostream>

using namespace std;

int main() {

	int a, b;
	cin >> a >> b;

	cout << "a+b = " << a + b << endl; // 16
	cout << "a-b = " << a - b << endl; // 6
	cout << "a*b = " << a*b << endl; // 55
	cout << "a/b = " << a / b << endl; // exp o/p 2.2 ac. o/p 2

	cout << "a/b = " << a * 1.0 / b << endl; // exp o/p 2.2 ac. o/p 2
	cout << "a/b = " << a / (b * 1.0) << endl; // exp o/p 2.2 ac. o/p 2

	cout << "a/b = " << (float)a / b << endl; // explicity type-casting
	cout << "a/b = " << float(a) / b << endl; //
	cout << "a/b = " << static_cast<float>(a) / b << endl; //

	cout << "a%b = " << a % b << endl; // 1

	cout << "3+5*4 = " << 3 + 5 * 4 << endl;
	cout << "8-4/2 = " << 8 - 4 / 2 << endl;
	cout << "(3+5)*4 = " << (3 + 5) * 4 << endl;
	cout << "(8-4)/2 = " << (8 - 4) / 2 << endl;
	cout << "100/10*10 = " << 100 / 10 * 10 << endl;
	cout << "5-2+3 = " << 5 - 2 + 3 << endl;

	return 0;
}