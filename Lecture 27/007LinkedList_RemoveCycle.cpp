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

// time : O(n)
// space: O(1)

void removeCycle(ListNode* head) {

	ListNode* slow = head;
	ListNode* fast = head;

	while (true) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			break;
		}
	}

	// slow and fast are at the meeting point

	slow = head;

	while (slow->next != fast->next) {
		slow = slow->next;
		fast = fast->next;
	}

	// slow->next and fast->next they are pointing to the start of the cycle
	// therefore fast is at the tail of the tail of the linkedList

	fast->next = NULL;

}

int main() {

	ListNode* head = new ListNode(10);
	head->next = new ListNode(20);
	head->next->next = new ListNode(30);
	head->next->next->next = new ListNode(40);
	head->next->next->next->next = new ListNode(50);
	head->next->next->next->next->next = new ListNode(60);
	head->next->next->next->next->next->next = head->next->next;

	removeCycle(head);

	printLinkedList(head);

	return 0;
}