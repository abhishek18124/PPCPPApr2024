#include<iostream>
#include<unordered_map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	unordered_map<char, node*> childMap;
	int freq;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
		this->freq = 0;
	}

};

class trie {
	node* root;
	int n; // to store size of trie

public :

	trie() {
		root = new node('#');
		n = 0;
	}

	// time : on avg. len(str) * const
	void insert(string str) {
		node* cur = root;
		for (char ch : str) {
			// check if cur node has a child node whose value is ch
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				// cur node doesn't have a child node whose value is ch
				node* n = new node(ch);
				cur->childMap[ch] = n;
			}
			cur = cur->childMap[ch];
			cur->freq++;
		}
		cur->terminal = true;
		n++;
	}

	// time : len of str

	string longestCommonPrefix(string str) {

		node* cur = root;
		string ans = "";

		for (char ch : str) {
			cur = cur->childMap[ch];
			if (cur->freq != n) break; // here n is no. of words in the trie
			ans += ch;
		}

		return ans;

	}


};



int main() {

	string words[] = {"flow", "floor", "fly"};

	// time : mn + n ~ O(mn)
	// space : O(mn) due to trie

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	cout << t.longestCommonPrefix(words[0]) << endl;

	return 0;
}