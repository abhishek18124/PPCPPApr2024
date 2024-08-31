#include<iostream>
#include<vector>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

int countPaths(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {
		return 0;
	}

	// recursive case

	int cnt = 0;

	// 1. ask your friend to cnt no. of paths in LST that start at the root whose sum is equal to targetSum

	cnt += countPaths(root->left, targetSum - root->val);

	// 2. ask your friend to cnt no. of paths in RST that start at the root whose sum is equal to targetSum

	cnt += countPaths(root->right, targetSum - root->val);

	if (root->val == targetSum) cnt++;

	return cnt;

}

int dfs(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {
		return 0;
	}

	// recursive case

	int cnt = 0;

	// decide for the root node

	// 1. don't use root node

	// 1.a. recursively, count no of paths in the leftSubtree whose sum is equal to targetSum

	cnt += dfs(root->left, targetSum);

	// 2.a. recursively,count no of paths in the rightSubtree whose sum is equal to targetSum

	cnt += dfs(root->right, targetSum);

	// 2. use root node

	// 2.a count no. of paths that start at the root whose sum is equal to targetSum

	cnt += countPaths(root, targetSum);

	return cnt;

}

int pathSum(TreeNode* root, int targetSum) {

	return dfs(root, targetSum);

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(1);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int targetSum = 8;

	cout << pathSum(root, targetSum) << endl;

	return 0;
}