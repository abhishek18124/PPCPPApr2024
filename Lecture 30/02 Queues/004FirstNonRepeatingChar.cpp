#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<char> q;
	int freqMap[26] = {0};

	char ch;

	while (true) {

		cin >> ch;

		if (ch == '.') break;

		freqMap[ch - 'a']++;
		if (freqMap[ch - 'a'] == 1) {
			// as of now, ch is non-repeating therefore track ch
			q.push(ch);
		}

		while (!q.empty() and freqMap[q.front() - 'a'] > 1) {
			q.pop();
		}

		if (q.empty()) {
			cout << -1;
		} else {
			cout << q.front();
		}

	}

	return 0;
}