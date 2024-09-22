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

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

ListNode* findMidPoint(ListNode* head) {
	if (!head) { // head == NULL
		return head;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

ListNode* mergeSortedLinkedListIterative(ListNode* head1, ListNode* head2) {

	if (head1 == NULL) {
		return head2;
	}

	if (head2 == NULL) {
		return head1;
	}

	// head1 != NULL and head2 != NULL

	ListNode* head; // points to the head of the merged LinkedList
	ListNode* temp; // points to the tail of the linkedList under-construction

	if (head1->val < head2->val) {

		head = head1;
		temp = head1;
		head1 = head1->next;

	} else {

		head = head2;
		temp = head2;
		head2 = head2->next;

	}

	while (head1 != NULL and head2 != NULL) {

		if (head1->val < head2->val) {

			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;

		} else {

			temp->next = head2;
			temp = temp->next;
			head2 = head2->next;

		}

	}

	if (head1 != NULL) {

		temp->next = head1;

	}

	if (head2 != NULL) {

		temp->next = head2;

	}

	return head;

}

// t(n) = 2t(n/2) + n.c
// t(0) = c
// t(1) = c

// time : O(nlogn)
// space: O(logn) due to fn call stack

ListNode* mergeSort(ListNode* head1) {

	// base case

	if (head1 == NULL || head1->next == NULL) {
		// LinkedList is empty || LinkedList has a single node
		return head1; // LinkedList is already sorted
	}

	// recursive case

	// LinkedList has >= 2 nodes

	// 1. divide the given LinkedList around the midPoint

	ListNode* midPoint = findMidPoint(head1);
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	// 2. recursively sort the two subLists

	head1 = mergeSort(head1);
	head2 = mergeSort(head2);

	// 3. merge the two sorted subLists such that the merged LinkedList is sorted

	return mergeSortedLinkedListIterative(head1, head2);

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	printLinkedList(head);

	head = mergeSort(head);

	printLinkedList(head);

	return 0;
}