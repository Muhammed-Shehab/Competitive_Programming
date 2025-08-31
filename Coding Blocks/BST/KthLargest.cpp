#include<iostream>
using namespace std;

// Node structure for BST
struct Node {
	int data;
	Node *left, *right;
	Node(int d) {
		data = d;
		left = right = nullptr;
	}
};

// Insert a key into BST
Node* insert(int key, Node *root) {
	if (!root) return new Node(key);

	if (root->data < key) root->right = insert(key, root->right);
	else root->left = insert(key, root->left);

	return root;
}

// Find K-th largest element in BST using reverse inorder traversal
void kthLargest(Node *root, int &k, int &ans) {
	if (!root || k <= 0) return;

	// Traverse right subtree first (larger elements)
	kthLargest(root->right, k, ans);

	// Decrement k after visiting a node
	k--;
	if (k == 0) {
		ans = root->data; // Found the K-th largest
		return;
	}

	// Traverse left subtree
	kthLargest(root->left, k, ans);
}

int main() {
	int n; 
	cin >> n;
	Node *root = nullptr;

	// Insert elements into BST
	for (int i = 0; i < n; i++) {
		int val; 
		cin >> val;
		root = insert(val, root);
	}

	int k; 
	cin >> k;

	int ans = -1;
	kthLargest(root, k, ans);

	cout << ans;
	return 0;
}
