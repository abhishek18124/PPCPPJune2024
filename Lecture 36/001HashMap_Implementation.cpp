/*

	Implementation of HashMap/HashTable

*/

#include<iostream>

using namespace std;

class node {

public :

	int K;
	int V;
	node* next;

	node(int K, int V) {
		this->K = K;
		this->V = V;
		this->next = NULL;
	}

};

class HashMap {
	int N; //  to store the hash table capacity
	int M; //  to store the hash table size
	double L; // to store the load factor threshold

	node** T; // to store the pointer to the  dynamic
	// array that represents the hash table

	int hashFn(int K) {
		// transform K into a hash index
		return K % N;
	}

	void transfer(node* head) {
		// 1. rehash (K, V) pairs present in the linkedList represented
		//    by "head" pointer to the updated hashMap

		// 2. release memory allocated for the linkedList represented
		//    by "head" pointer
	}

	void rehash() {

		// 1. save pointer to the current hashMap and its capacity

		// 2. create a hashMap with double capacity

		// 3. transfer (K, V) pairs from old hashMap to the updated hashMap

		// 4. release the memory allocated to the old hashMap

	}

public :

	HashMap(int N = 5, double L = 0.7) {
		this->N = N;
		this->M = 0;
		this->L = L;

		T = new node*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL;
		}
	}

	void insert(int K, int V) {

		// 1. transform the key into hash index using the hash function
		int hashIdx = hashFn(K);

		// 2. create a node with the given (K, V) pair and insert it at
		//    head of the linkedList stored at the hash index
		node* n = new node(K, V);

		// 3. update the pointer to the head of the linkedList stored at
		//    the hash index such that it holds the address of the newly
		//    created node
		n->next = T[hashIdx];
		T[hashIdx] = n;
		M++;

		// 4. rehash, if loadFactor exceeds the loadFactor Threshold
		double loadFactor = M * 1.0 / N;
		if (loadFactor > L) {
			// rehash ...
		}

	}

	node* find(int K) {

		// 1. transform the key into hash index using the hash function
		int hashIdx = hashFn(K);

		// 2. search for the node with the given key in the  linkedList
		//    stored at the hash index
		node* temp = T[hashIdx];
		while (temp != NULL) {
			if (temp->K == K) {
				// you've found the node whose key matches the given key
				break;
			}
			temp = temp->next;
		}

		return temp;

	}

	void erase(int K) {

		// 1. transform the key into hash index using the hash function
		int hashIdx = hashFn(K);

		// 2. delete the node with the given key from the linkedList
		//    stored at the hash index
		node* temp = T[hashIdx];
		if (temp == NULL) {
			// linkedList at hashIdx is empty that means given K doesn't exist
		} else if (temp->K == K) {
			// delete at head
			T[hashIdx] = temp->next;
			delete temp;
			M--;
		} else {
			node* prev = NULL;
			node* cur = T[hashIdx];
			while (cur != NULL) {
				if (cur->K == K) {
					// delete cur node
					prev->next = cur->next; // prev can never be NULL since we've already handled deletion at head above
					delete cur;
					M--;
					break;
				}
				prev = cur;
				cur = cur->next;
			}
		}

		return;

	}

	void printLinkedList(node* head) {
		while (head) { // head != NULL
			cout << "(" << head->K << ", " << head->V << ") ";
			head = head->next;
		}
		cout << endl;
	}

	void printHashMap() {
		// iterate over buckets in the hashMap
		for (int i = 0; i < N; i++) {
			// print the linkedList stored ith bucket of the hashMap
			cout << i << " : ";
			printLinkedList(T[i]);
		}
		cout << endl;
	}
};

int main() {

	HashMap hm;

	hm.insert(7, 49);
	hm.insert(2, 4);
	hm.insert(0, 0);
	hm.insert(5, 25);
	hm.insert(10, 100);

	hm.printHashMap();

	int key = 7;
	node* n = hm.find(key);
	if (n != NULL) {
		// key is present
		cout << n->V << endl;
	}

	key = 12;
	n = hm.find(key);
	if (n != NULL) {
		// key is present
		cout << n->V << endl;
	} else {
		cout << key << " not found" << endl;
	}

	key = 5;
	hm.erase(key);
	hm.printHashMap();

	key = 2;
	hm.erase(key);
	hm.printHashMap();

	return 0;
}