/*

Implementation of the TRIE data structure to store non-negative integers.

Assume integer has 32-bit representation.

*/

#include<iostream>

using namespace std;

class node {

public:

	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1

	node() {
		this->left = NULL;
		this->right = NULL;
	}
};


class trie {

	node* root;

public :

	trie() {
		root = new node();
	}

	void insert(int n) {
		node* cur = root;
		for (int k = 31; k >= 0; k--) {
			int kthBit = (n >> k) & 1;
			if (kthBit) {
				// kthBit of n is set
				if (cur->right == NULL) {
					// cur node doesn't have a right child i.e. a child node with bitval 1
					cur->right = new node();
				}
				cur = cur->right;
			} else {
				// kthBit of n is not set
				if (cur->left == NULL) {
					// cur node doesn't have a left child i.e. a child node with bitval 0
					cur->left = new node();
				}
				cur = cur->left;
			}
		}

	}

	bool search(int n) {
		node* cur = root;
		for (int k = 31; k >= 0; k--) {
			int kthBit = (n >> k) & 1;
			if (kthBit) {
				// kthBit is set
				if (cur->right == NULL) {
					return false;
				}
				cur = cur->right;
			} else {
				// kthBit is not set
				if (cur->left == NULL) {
					return false;
				}
				cur = cur->left;
			}
		}
		return true;
	}
};

int main() {

	int arr[] = {2, 4, 8, 5, 10};
	int n = sizeof(arr) / sizeof(int);

	trie t;
	for (int i = 0; i < n; i++) {
		t.insert(arr[i]);
	}

	int brr[] = {1, 2, 5, 10, 25, 0};
	int m = sizeof(brr) / sizeof(int);

	for (int i = 0; i < m; i++) {
		t.search(brr[i]) ? cout << brr[i] << " is present" << endl :
		                        cout << brr[i] << " is absent" << endl;
	}

	cout << endl;

	return 0;
}