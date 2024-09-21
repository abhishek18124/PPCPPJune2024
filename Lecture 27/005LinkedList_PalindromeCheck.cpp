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

ListNode* reverseIterative(ListNode* head) {

	ListNode* cur = head;
	ListNode* prev = NULL;

	while (cur != NULL) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;
}

ListNode* findMidPoint(ListNode* head) {
	if (head == NULL) {
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

ListNode* findMidPoint(ListNode *head) {

	if (head == NULL) {
		// LinkedList is empty
		return head;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;

}

ListNode* reverseIterative(ListNode* head) {

	ListNode* prev = NULL;
	ListNode* cur = head;

	while (cur != NULL) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;

}

// time = 3n/2 steps . const ~ O(n)
// space = O(1)

bool isPalindrome(ListNode* head) {

	// 1. find the midPoint

	ListNode* midPoint = findMidPoint(head); // n/2

	// 2. divide the given LinkedList around the midPoint

	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	// 3. reverse the 2nd subList

	head2 = reverseIterative(head2); // n/2

	// 4. comparet the 1st and the 2nd subLists

	while (head2 != NULL) { // n/2

		if (head->val != head2->val) {
			return false;
		}

		head = head->next;
		head2 = head2->next;

	}

	// given LinkedList is a palindrome
	return true;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	isPalindrome(head) ? cout << "palindrome" << endl : cout << "not a palindrome" << endl;

	return 0;
}