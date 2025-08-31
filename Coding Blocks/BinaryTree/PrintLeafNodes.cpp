#include<iostream>
#include<queue>
using namespace std;

/*
Problem: Given a binary tree, print all the leaf nodes.

Approach:
1. Build the binary tree from level-order input using a queue.
   - Input -1 represents NULL nodes.
   - Use a queue to iteratively construct children for each node.
2. Traverse the tree using recursion to print leaf nodes.
   - A node is a leaf if both left and right children are NULL.

Time Complexity:
- Building the tree: O(n), where n is the number of nodes
- Printing leaf nodes: O(n)
Space Complexity:
- Queue for building tree: O(width of tree)
- Recursive call stack: O(height of tree)
*/

// Node structure for the binary tree
struct Node {
	int data;
	Node *left, *right;

	Node (int val) {
		data = val;
		left = right = nullptr;
	}
};

// Function to build a binary tree using level-order input
Node* builtTree() {
	int val; cin >> val;

	if (val == -1) return nullptr; // empty tree

	Node *root = new Node(val);
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node *temp = q.front();
		q.pop();

		int lVal; cin >> lVal;
		if (lVal != -1) {
			temp->left = new Node(lVal);
			q.push(temp->left);
		}

		int rVal; cin >> rVal;
		if (rVal != -1) {
			temp->right = new Node(rVal);
			q.push(temp->right);
		}
	}
	return root;
}

// Function to recursively print all leaf nodes
void printLeaf (Node *root) {
	if (!root) return;

	if (!root->left && !root->right) cout << root->data << ' '; // leaf node

	printLeaf(root->left);
	printLeaf(root->right);
}

int main() {
	Node *root = builtTree(); // build tree from input
	printLeaf(root); // print all leaf nodes
	return 0;
}
