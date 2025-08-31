#include<iostream>
using namespace std;

/*
Problem: Given a binary tree, calculate the sum of all nodes.

Approach:
1. Build the binary tree recursively using input in the format:
   - Node value
   - Boolean indicating if the node has a left child
   - Boolean indicating if the node has a right child
   (Use `boolalpha` for reading true/false as input)
2. Use recursion to calculate the sum:
   - Base case: If node is NULL, return 0
   - Recursive case: Sum = node's value + sum(left subtree) + sum(right subtree)

Time Complexity: O(n), where n is number of nodes
Space Complexity: O(height of tree) due to recursion
*/

// Node structure for the binary tree
struct Node {
	int data;
	Node *left;
	Node *right;

	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

// Recursive function to build binary tree
Node* buildtree() {
	int val;
	bool hasleft, hasright;

	// Read node value
	if (!(cin >> val));

	Node *root = new Node(val);

	// Read if left child exists
	cin >> boolalpha >> hasleft;
	if (hasleft) root->left = buildtree();

	// Read if right child exists
	cin >> boolalpha >> hasright;
	if (hasright) root->right = buildtree();

	return root;
}

// Recursive function to calculate sum of nodes
int sumNodes(Node *root) {
	if (!root) return 0;
	return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
	Node *root = buildtree(); // Build tree from input
	cout << sumNodes(root);   // Print sum of all nodes
	return 0;
}
