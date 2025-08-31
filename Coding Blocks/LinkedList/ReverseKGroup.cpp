#include<iostream>
using namespace std;

// Definition of singly linked list node
struct Node {
	int data;
	Node* next;
	Node(int val) {
		data = val;
		next = NULL;
	} 
};

// Reverse linked list in groups of k
Node* reverseK(Node *&head, int k) {
	if (!head || k == 1) return head; // trivial cases

	// Count total nodes
	Node *temp = head;
	int count = 0;
	while (temp) {
		temp = temp->next;
		count++;
	}

	if (k > count) return head; // no full group to reverse

	Node *curr = head, *prev = NULL, *next = NULL;
	Node *newHead = NULL, *tailPrev = NULL;

	while (k <= count) {
		Node *grpPrev = NULL, *grpTail = curr;

		// Reverse current group of k nodes
		for (int i = 0; i < k; i++) {
			next = curr->next;
			curr->next = grpPrev;
			grpPrev = curr;
			curr = next;
		}

		if (!newHead) newHead = grpPrev; // first group → new head

		if (tailPrev) tailPrev->next = grpPrev; // connect previous group

		tailPrev = grpTail; // update tail for next connection
		count -= k;
	}

	if (tailPrev) tailPrev->next = curr; // connect remaining nodes
	return newHead;
}

// Print linked list
void printNode(Node *head) {
	Node *temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

// Insert node at tail
void insertAtTail(Node *&head, int val) {
	if (!head) {
		head = new Node(val);
		return;
	} 
	Node *newN = new Node(val);
	Node *temp = head;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = newN;
}

int main() {
	int n, k;
	cin >> n >> k;
	Node *head = NULL;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		insertAtTail(head, val);
	}

	head = reverseK(head, k); // reverse in groups
	printNode(head);           // print final list

	return 0;
}
