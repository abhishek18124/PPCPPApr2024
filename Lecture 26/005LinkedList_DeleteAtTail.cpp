#include<iostream>

using namespace std;

class ListNode {

public :

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

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

void deleteAtHead(ListNode*& head) {

	if (!head) { // head == NULL
		// linkedList is empty
		return;
	}

	ListNode* temp = head;
	head = head->next;
	delete temp;
}

// time : O(n)

void deleteAtTail(ListNode*& head) {

	if (head == NULL) {
		// LinkedList is empty
		return;
	}

	if (head->next == NULL) {
		// LinkedList has 1 node
		deleteAtHead(head);
		return;
	}

	ListNode* cur = head;
	ListNode* prev = NULL;

	while (cur->next != NULL) {
		prev = cur;
		cur = cur->next;
	}

	// cur is pointing to tailNode

	prev->next = NULL;
	delete cur;

}

int main() {

	ListNode* head = NULL; // linked list is initially empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	deleteAtTail(head);

	printLinkedList(head);

	return 0;
}