#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int p;
	cin >> p;

	double ans = 0;

	while (ans * ans <= n) {
		ans = ans + 1;
	}

	ans = ans - 1;

	int i = 1;
	double inc = 0.1;

	while (i <= p) {


		while (ans * ans <= n) {
			ans = ans + inc;
		}

		ans = ans - inc;
		inc = inc / 10;

		i = i + 1;

	}

	cout << ans << endl;

	cout << 8.24621 * 8.24621 << endl;

	cout << sqrt(68) << endl;

	return 0;
}