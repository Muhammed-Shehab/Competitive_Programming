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

// Function to segregate odd and even nodes
Node* seperateLL(Node *head) {
	Node *oddH = NULL, *oddT = NULL;   // head & tail for odd list
	Node *evenH = NULL, *evenT = NULL; // head & tail for even list

	while (head) {
		if ((head->data & 1) == 1) { // odd node
			if (oddH) {
				oddT->next = head;
				oddT = oddT->next;
			} else {
				oddH = oddT = head;
			}
		} else { // even node
			if (evenT) {
				evenT->next = head;
				evenT = evenT->next;
			} else {
				evenT = evenH = head;
			}
		}
		head = head->next;
	}

	if (evenT) evenT->next = NULL; // terminate even list

	if (oddH) {             // attach even list after odd list
		oddT->next = evenH;
		return oddH;         // new head is odd head
	}
	return evenH;            // only even nodes exist
}

// Insert node at tail
void insertAtTail(Node *&head, int val) {
	if (head == NULL) {
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

// Print linked list
void printLL(Node *head) {
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main() {
	int n; 
	cin >> n;
	Node *head = NULL;

	while (n--) {
		int val; 
		cin >> val;
		insertAtTail(head, val);
	}

	head = seperateLL(head); // separate odd and even nodes
	printLL(head);           // print final list
	return 0;
}
