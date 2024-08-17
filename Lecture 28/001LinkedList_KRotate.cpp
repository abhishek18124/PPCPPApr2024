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
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

// ListNode* rotateLinkedList(ListNode* head, int k) {

// 	// 1. form a loop by connecting the tail ListNode of  the
// 	//    linkedList with the head ListNode of the linkedList

// 	// 2. get hold of the pointer to the new tail ListNode
// 	//    that can be found at the (n-(k%n)-1)th index

// 	// 3. get hold of the pointer to the new head ListNode

// 	// 4. remove the cycle by updating the next pointer of
// 	//    the new tail ListNode to contain the NULL address

// }

// ListNode* rotateLinkedList(ListNode* head, int k) {

// ListNode* fast = head;

// int i = 1;
// while (i <= k) {
// 	fast = fast->next;
// 	i++;
// }

// ListNode* slow = head;
// while (fast->next != NULL) {
// 	slow = slow->next;
// 	fast = fast->next;
// }

// // slow is at the k+1th last node i.e. newTail
// // fast is at the tail of the linkedList

// 	fast->next = head;

// 	ListNode* newTail = slow;
// 	ListNode* newHead = newTail->next;

// 	newTail->next = NULL;
// 	return newHead;

// }

int computeLengthIterative(ListNode* head) {

	int cnt = 0;

	while (head != NULL) {
		cnt++;
		head = head->next;
	}

	return cnt;

}

ListNode* kthLastNode(ListNode* head, int k) {

	// move fast pointer k-steps fwd

	ListNode* fast = head;
	int i = 1;
	while (i <= k) {
		fast = fast->next;
		i++;
	}

	ListNode* slow = head;
	while (fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;

}


ListNode* rotateLinkedList(ListNode* head, int k) {

	if (head == NULL || head->next == NULL) {
		return head;
	}

	int n = computeLengthIterative(head);
	k = k % n;

	if (k == 0) {
		return head;
	}

	ListNode* newTail = kthLastNode(head, k + 1);
	ListNode* newHead = newTail->next;

	// 1. form a loop by connecting the tail ListNode of  the
	//    linkedList with the head ListNode of the linkedList

	ListNode* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}

	// cur is pointing to the tail node of the linkedList

	cur->next = head;

	// 2. remove the cycle by updating the next pointer of
	//    the new tail ListNode to contain the NULL address

	newTail->next = NULL;
	return newHead;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int k = 16;

	head = rotateLinkedList(head, k);

	printLinkedList(head);

	return 0;
}