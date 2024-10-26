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


int findMinimum(TreeNode* root) {

	if (root == NULL) {
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	return root->val;

}


int findMaximum(TreeNode* root) {

	if (root == NULL) {
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	return root->val;

}

// time : O(n.h)

bool checkBST(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	// check if the given tree is a BST

	// 1. ask your friend to check if the LST is a BST

	bool leftIsBst = checkBST(root->left);

	// 2. ask your friend to check if the RST is a BST

	bool rightIsBst = checkBST(root->right);

	// 3. check if the BST prop. works at the root node

	bool rootIsBst = root->val > findMaximum(root->left) and root->val < findMinimum(root->right) ? true : false;

	return leftIsBst and rightIsBst and rootIsBst;

}

class triple {

public:

	bool isBst;
	int minVal;
	int maxVal;

};

// time : O(n)

triple checkBSTEfficient(TreeNode* root) {

	triple t;

	// base case

	if (root == NULL) {

		t.isBst = true;
		t.minVal = INT_MAX;
		t.maxVal = INT_MIN;

		return t;

	}

	// recursive case

	// 1. ask your friend to check if the leftSubtree is a BST and also find the minimum and maximum values of the leftSubtree

	triple left = checkBSTEfficient(root->left);

	// 2. ask your friend to check if the rightSubtree is a BST and also find the minimum and maximum values of the rightSubtree

	triple right = checkBSTEfficient(root->right);

	// 3. check if the BST prop. works at the root node

	bool rootIsBst = root->val > left.maxVal and root->val < right.minVal ? true : false;

	t.isBst = left.isBst and right.isBst and rootIsBst;
	t.minVal = min(left.minVal, min(right.minVal, root->val));
	t.maxVal = max(left.maxVal, max(right.maxVal, root->val));

	return t;

}

// time : O(n)

bool checkBSTEfficientUsingRanges(TreeNode* root, long long lb, long long ub) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	return root->val > lb and root->val < ub  and
	       checkBSTEfficientUsingRanges(root->left, lb, root->val) and
	       checkBSTEfficientUsingRanges(root->right, root->val, ub);

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

	t.isBst ? cout << "true" << endl : cout << "false" << endl;

	// constraints INT_MIN <= node.val <= INT_MAX

	long long lb = (long long)INT_MIN - 1; // LLONG_MIN
	long long ub = (long long)INT_MAX + 1; // LLONG_MAX

	checkBSTEfficientUsingRanges(root, lb, ub) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}