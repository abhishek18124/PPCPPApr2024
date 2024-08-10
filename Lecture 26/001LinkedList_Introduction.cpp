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

// time : O(1)

void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);

	n->next = head;

	head = n;

}

// time : O(n)

void printLinkedList(ListNode* head) {

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

int main() {

	// ListNode* n = new ListNode(10);

	// cout << (*n).val << endl;
	// cout << n->val << endl;

	// if (n->next == NULL) {
	// 	cout << "n->next is NULL" << endl;
	// }

	ListNode* head = NULL; // LinkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	if (head == NULL) {
		cout << "LinkedList is empty" << endl;
	}

	printLinkedList(head);
	printLinkedList(head);

	return 0;
}