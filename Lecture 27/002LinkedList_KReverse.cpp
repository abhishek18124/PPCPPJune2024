#include<iostream>

using namespace std;

class ListNode {
public:

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

// [hw] leetcode - reverse nodes in k-group
// time :  no. of calls * time spent in each call = (n/k) * (k) = n ~ O(n)
// space : O(n/k) due to fn call stack
// [hw] : try to solve this itertively

ListNode* kReverse(ListNode* head, int k) {

	// base case
	if (head == NULL) {
		return head;
	}

	// recursive case

	// 1. reverse the 1st k nodes

	ListNode* prev = NULL;
	ListNode* cur = head;

	int i = 1;
	while (cur != NULL and i <= k) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
		i++;
	}

	// 2. ask your friend to k-reverse the remaining linkedList

	ListNode* headFromMyFriend = kReverse(cur, k);
	head->next = headFromMyFriend;
	return prev;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 80);
	insertAtHead(head, 70);
	insertAtHead(head, 60);
	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int k = 3;

	head = kReverse(head, k);

	printLinkedList(head);

	return 0;
}