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

// t(n) = k + t(n-k)
// t(0) = c

// time : O(n)
// space: O(n/k) due to fn call-stack

ListNode* kReverse(ListNode* head, int k) {

	// base case

	if (head == NULL) {
		return head;
	}

	// recursive case

	ListNode* cur = head;
	ListNode* prev = NULL;

	int i = 1;

	while (i <= k and cur != NULL) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
		i++;
	}

	ListNode* headFromMyFriend = kReverse(cur, k);
	head->next = headFromMyFriend;

	return prev;
}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 60);
	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int k = 2;

	head = kReverse(head, k);

	printLinkedList(head);

	return 0;
}