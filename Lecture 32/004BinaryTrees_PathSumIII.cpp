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

int countPaths(TreeNode* root, long long targetSum) {

	// base case

	if (root == NULL) {
		return 0;
	}

	// recursive case

	// count no. of paths in the given tree that start at the root and whose sum is equal to targetSum

	int cnt = 0;

	// 1. ask your friend to count no. of paths in the leftSubtree that start at the root whose sum is equal to targetSum - root->val
	cnt += countPaths(root->left, targetSum - root->val);

	// 2. ask your friend to count no. of paths in the rightSubtree that start at the root whose sum is equal to targetSum - root->val
	cnt += countPaths(root->right, targetSum - root->val);

	if (root->val == targetSum) cnt++;

	return cnt;

}

// time : O(n^2)

int pathSum(TreeNode* root, int targetSum) {

	// base case
	if (root == NULL) {
		return 0;
	}

	// recursive case

	// cnt no. of paths in the given tree whose sum is equal to targetSum

	// decide for the root node

	int cnt = 0;

	// option 1 : use the root node

	cnt += countPaths(root, targetSum); // linear time

	// option 2 : don't use the root node

	// 2.1 ask your friend to count no. of paths in the leftSubtree whose sum is equal to targetSum
	cnt += pathSum(root->left, targetSum);

	// 2.2 ask your friend to count no. of paths in the rightSubtree whose sum is equal to targetSum
	cnt += pathSum(root->right, targetSum);

	return cnt;

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