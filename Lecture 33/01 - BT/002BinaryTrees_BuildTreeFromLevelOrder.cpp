/*

given the level order traversal of a binary tree, design an algorithm to construct a
binary tree from it.

Example
	Input: 10 20 30 40 50 -1 60 -1 -1 70 -1 -1 -1 -1 -1
*/

#include<iostream>
#include<queue>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

TreeNode* buildTree() {

	int data;
	cin >> data;

	TreeNode* root = new TreeNode(data);
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {

		TreeNode* front = q.front();
		q.pop();

		// construct the left and right child of the front node

		int leftData;
		cin >> leftData;

		if (leftData != -1) {
			TreeNode* leftchild = new TreeNode(leftData);
			front->left = leftchild;
			q.push(leftchild);
		}

		int rightData;
		cin >> rightData;

		if (rightData != -1) {
			TreeNode* rightchild = new TreeNode(rightData);
			front->right = rightchild;
			q.push(rightchild);
		}

	}

	return root;

}

void printLevelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		TreeNode* front = q.front(); q.pop();
		if (front == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->val << " ";
			if (front->left) q.push(front->left);
			if (front->right)q.push(front->right);
		}
	}

}


int main() {

	TreeNode* root = buildTree();
	printLevelOrder(root);

	return 0;
}