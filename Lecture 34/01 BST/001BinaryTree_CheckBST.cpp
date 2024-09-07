/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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

// time : O(hgt of BST)

int findMinimum(TreeNode* root) {

	if (root == NULL) {
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	return root->val;

}

// time : O(hgt of BST)

int findMaximum(TreeNode* root) {

	if (root == NULL) {
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	return root->val;

}

// time : O(nh) worst case O(n^2) on avg. O(nlogn)

bool checkBST(TreeNode* root) {

	// base case

	if (root == NULL) {
		// empty tree is a BST
		return true;
	}

	// recursive case

	// check if the given tree is a BST

	// 1. recursively, check if the leftSubtree is a BST

	bool leftIsBst = checkBST(root->left);

	// 2. recursively, check if the rightSubtree is a BST

	bool rightIsBst = checkBST(root->right);

	// 3. check if the BST property works at the root node

	bool rootIsBst = root->val > findMaximum(root->left) and
	                 root->val < findMinimum(root->right) ? true : false;

	return leftIsBst and rightIsBst and rootIsBst;

}

class triple {

public:

	bool isbst;
	int maxVal;
	int minVal;

};

// time : O(n)

triple checkBSTEfficient(TreeNode* root) {

	triple t;

	// base case

	if (root == NULL) {
		t.isbst = true;
		t.minVal = INT_MAX;
		t.maxVal = INT_MIN;
		return t;
	}

	// recursive case

	triple left = checkBSTEfficient(root->left);
	triple right = checkBSTEfficient(root->right);

	bool rootIsBst = root->val > left.maxVal and
	                 root->val < right.minVal ? true : false;

	t.isbst = left.isbst and right.isbst and rootIsBst;
	t.minVal = min(left.minVal, min(right.minVal, root->val));
	t.maxVal = max(left.maxVal, max(right.maxVal, root->val));

	return t;


}

// [-INF, +INF]
// (-INF-1, INF+1)

bool checkBSTEfficientRange(TreeNode* root, long long lb, long long ub) {

	// base case
	if (root == NULL) {
		return true;
	}

	// recursive case
	return root->val > lb and root->val < ub and
	       checkBSTEfficientRange(root->left, lb, root->val) and
	       checkBSTEfficientRange(root->right, root->val, ub);

}


int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(0);

	checkBST(root) ? cout << "true" << endl : cout << "false" << endl;

	triple t = checkBSTEfficient(root);
	t.isbst ? cout << "true" << endl : cout << "false" << endl;

	long long lb = (long long)INT_MIN - 1;
	long long ub = (long long)INT_MAX + 1; // (lb, ub)

	checkBSTEfficientRange(root, lb, ub) ? cout << "true" << endl : cout << "false" << endl;


	return 0;
}