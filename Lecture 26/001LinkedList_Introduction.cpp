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

void insertAtHead(ListNode*& head, int val) { // we are passing address of the headNode by reference

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

ListNode* insertAtHead2(ListNode* head, int val) { // we are passing address of the headNode by reference

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

	return head;

}

void printLinkedList(ListNode* head) { // we are passing address of the headNode by value

	while (head != NULL) {

		cout << head->val << " ";
		head = head->next;

	}

	cout << endl;

}

int main() {

	// ListNode* n = new ListNode(10);

	// cout << n->val << endl;

	// if (n->next == NULL) {
	// 	cout << "next is NULL" << endl;
	// }

	ListNode* head1 = NULL; // linkedList is empty

	insertAtHead(head1, 50);
	insertAtHead(head1, 40);
	insertAtHead(head1, 30);
	insertAtHead(head1, 20);
	insertAtHead(head1, 10);

	// if (head1 == NULL)cout << "LinkedList is still empty" << endl;

	printLinkedList(head1);

	printLinkedList(head1);

	ListNode* head2 = NULL; // linkedList is empty

	head2 = insertAtHead2(head2, 500);
	head2 = insertAtHead2(head2, 400);
	head2 = insertAtHead2(head2, 300);
	head2 = insertAtHead2(head2, 200);
	head2 = insertAtHead2(head2, 100);

	printLinkedList(head2);


	return 0;
}