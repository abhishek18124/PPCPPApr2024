#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int add1(int y) {
	return 1 + y;
}

int add2(int y) {
	return 2 + y;
}

int add3(int y) {
	return 3 + y;
}

class addx {

public:

	int x;

	addx(int x) {
		this->x = x;
	}

	int operator()(int y) {
		return y + x;
	}

};

int main() {

	vector<int> inp = {1, 2, 3, 4, 5};

	for (int i = 0; i < inp.size(); i++) {
		cout << inp[i] << " ";
	}

	cout << endl;

	vector<int> out(inp.size());

	addx objOne(1); // obj is an object of addx in which the value of x is equal to 1
	// also, obj is a function object therefore it is callable

	transform(inp.begin(), inp.end(), out.begin(), objOne);

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	addx objTwo(2);

	transform(inp.begin(), inp.end(), out.begin(), objTwo);

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	addx objThree(3);

	transform(inp.begin(), inp.end(), out.begin(), objThree);

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	transform(inp.begin(), inp.end(), out.begin(), addx(4));

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;



	return 0;
}