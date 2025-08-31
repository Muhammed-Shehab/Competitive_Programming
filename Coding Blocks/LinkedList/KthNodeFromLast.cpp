#include<iostream>
using namespace std;

// Definition of singly linked list node
struct Node {
	int data;
	Node *next;
	Node(int val) {
		data = val;
		next = NULL;
	}
};

// Find the kth node from the end of the linked list
int findK(Node *head, int k) {
	int temp = k;
	Node *fstP = head; // fast pointer
	Node *scdP = head; // slow pointer

	// Move fast pointer k steps ahead
	while (temp--) {
		if (!fstP) return -1; // k is larger than list length
		fstP = fstP->next;
	}

	// Move both pointers until fast reaches the end
	while (fstP) {
		fstP = fstP->next;
		scdP = scdP->next;
	}

	return scdP->data; // slow pointer is at kth node from end
}

int main() {
	int val;
	cin >> val;

	Node *temp = new Node(val);
	Node *head = temp;

	// Build the linked list until -1 is encountered
	while (cin >> val && val != -1) {
		temp->next = new Node(val);
		temp = temp->next;
	}
	temp->next = NULL;

	int k; 
	cin >> k;

	cout << findK(head, k); // print kth node from end
	return 0;
}
