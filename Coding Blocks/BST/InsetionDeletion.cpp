#include<iostream>
#include<vector>
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
Node* insert(Node *root, int key) {
	if (!root) return new Node(key);

	if (key < root->data) root->left = insert(root->left, key);
	else root->right = insert(root->right, key);

	return root;
}

// Find minimum node in a BST (used for deletion)
Node* findMin(Node *root) {
	while (root && root->left) root = root->left;
	return root;
}

// Delete a key from BST
Node* deleteNode(int key, Node *root) {
	if (!root) return nullptr;

	if (key < root->data) root->left = deleteNode(key, root->left);
	else if (key > root->data) root->right = deleteNode(key, root->right);
	else {
		// Node with only right child or no child
		if (!root->left) {
			Node *temp = root->right;
			delete root;
			return temp;
		}
		// Node with only left child
		else if (!root->right) {
			Node *temp = root->left;
			delete root;
			return temp;
		}
		// Node with two children: replace with inorder successor
		Node *successor = findMin(root->right);
		root->data = successor->data;
		root->right = deleteNode(successor->data, root->right);
	}
	return root;
}

// Preorder traversal of BST
void preOdr(Node *root) {
	if (!root) return;

	cout << root->data << ' ';
	preOdr(root->left);
	preOdr(root->right);
}

int main() {
	int t; cin >> t;
	while (t--) {
		int m, n; cin >> m;
		vector<int> A1(m);
		for (int i = 0; i < m; i++) cin >> A1[i];
		cin >> n;
		vector<int> A2(n);
		for (int i = 0; i < n; i++) cin >> A2[i];

		Node *root = nullptr;

		// Insert nodes into BST
		for (int val : A1) {
			root = insert(root, val);
		}
		// Delete nodes from BST
		for (int val : A2) {
			root = deleteNode(val, root);
		}
		// Print preorder traversal
		preOdr(root);
		cout << endl;
	}
	return 0;
}
