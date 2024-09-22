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

public :

	trie() {
		root = new node('#');
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
	}

	// time : len of str

	string shortestUniquePrefix(string str) {
		node* cur = root;
		string ans = "";
		for (char ch : str) {
			ans += ch;
			cur = cur->childMap[ch];
			if (cur->freq == 1) {
				return ans;
			}
		}
		return ""; // str has no unique prefix
	}

};


int main() {

	// overall time = 2mn ~ O(mn)
	// space due to trie = O(mn) assuming all the m words start with different characters

	string words[] = {"code", "coder", "coding", "new", "neon"};

	// no. of words = m
	// len of each word = n
	// time spent on each word = n
	// therefore total time for insetion = O(mn)

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	// no. of words = m
	// len of each word = n
	// time spent on each word = n
	// therefore total time for finding shortest unique prefix = O(mn)

	for (string word : words) {
		cout << "prefix(" << word << ") = " << t.shortestUniquePrefix(word) << endl;
	}

	return 0;
}