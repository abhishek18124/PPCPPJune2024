#include<iostream>

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

// [HW] implement preOrder traversal iteratively

void printPreOrder(TreeNode* root) {

	// base case

	if (root == NULL) {
		// cout << -1 << " ";
		return;
	}

	// recursive case

	// 1. process the root node

	cout << root->val << " ";

	// 2. recursively, print the preOrder of the leftSubtree

	printPreOrder(root->left);

	// 2. recursively, print the preOrder of the rightSubtree

	printPreOrder(root->right);

}


// [HW] implement inOrder traversal iteratively

void printInOrder(TreeNode* root) {

	// base case

	if (root == NULL) {
		cout << -1 << " ";
		return;
	}

	// recursive case

	// 1. recursively, print the inOrder of the leftSubtree

	printInOrder(root->left);

	// 2. process the root node

	cout << root->val << " ";

	// 3. recursively, print the inOrder of the rightSubtree

	printInOrder(root->right);

}

// [HW] implement postOrder traversal iteratively

void printPostOrder(TreeNode* root) {

	// base case

	if (root == NULL) {
		cout << -1 << " ";
		return;
	}

	// recursive case

	// 1. recursively, print the postOrder of the leftSubtree

	printPostOrder(root->left);

	// 2. recursively, print the postOrder of the rightSubtree

	printPostOrder(root->right);

	// 3. process the root node

	cout << root->val << " ";

}



int main() {

	TreeNode* root = NULL; // tree is empty

	root = new TreeNode(10);
	root->left = new TreeNode(20);
	root->right = new TreeNode(30);
	root->left->left = new TreeNode(40);
	root->left->right = new TreeNode(50);
	root->right->right = new TreeNode(60);
	root->left->right->left = new TreeNode(70);

	printPreOrder(root);

	cout << endl;

	printInOrder(root);

	cout << endl;

	printPostOrder(root);

	cout << endl;
	return 0;
}