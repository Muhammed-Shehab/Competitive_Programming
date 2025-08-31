#include<iostream>
#include<sstream>
using namespace std;

/*
Problem: Given two binary trees, determine if they are identical.
Two binary trees are identical if they have the same structure and node values.

Approach:
1. Build each tree from a single line of input using istringstream:
   - Node value
   - "true"/"false" indicating if left child exists
   - "true"/"false" indicating if right child exists
2. Recursively compare the two trees:
   - Base case:
       * Both nodes null -> identical
       * One null and other non-null -> not identical
   - Recursive case: check left subtrees && check right subtrees

Time Complexity: O(n), n = number of nodes in the trees
Space Complexity: O(height of tree) due to recursion
*/

// Node structure for binary tree
struct Node {
	int data;
	Node *left, *right;
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

// Function to check if two trees are identical
bool isSame(Node *r1, Node *r2) {
	if (!r1 && !r2) return true;
	if (!r1 || !r2) return false;

	return (r1->data == r2->data) &&
	       isSame(r1->left, r2->left) &&
	       isSame(r1->right, r2->right);
}

// Recursive function to build a tree from string stream
Node* built(istringstream& ss) {
	string vals, lefts, rights;

	if (!(ss >> vals)) return nullptr;

	int val = stoi(vals);
	Node *root = new Node(val);

	if (!(ss >> lefts)) return root;
	if (lefts == "true") {
		root->left = built(ss);
	} 

	if (!(ss >> rights)) return root;
	if (rights == "true") {
		root->right = built(ss);
	} 

	return root;
}

int main() {
	Node *r1, *r2;
	string line1, line2;

	// Read tree inputs from single lines
	getline(cin, line1);
	getline(cin, line2);

	istringstream ss1(line1);
	r1 = built(ss1);

	istringstream ss2(line2);
	r2 = built(ss2);

	// Check if trees are identical
	cout << (isSame(r1, r2) ? "true" : "false");
	return 0;
}
