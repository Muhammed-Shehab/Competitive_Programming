#include <iostream>
#include <vector>
using namespace std;

// Node structure for binary tree
struct Node {
    int data;
    Node *left, *right;
    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

// Build a BST from a sorted array (inorder array)
Node* build(vector<int>& inOdr, int left, int right) {
    if (left > right) return nullptr;

    int mid = (left + right) / 2;
    Node* root = new Node(inOdr[mid]);
    root->left = build(inOdr, left, mid - 1);
    root->right = build(inOdr, mid + 1, right);
    return root;
}

// Convert BST to Greater Sum Tree
void greaterSum(Node* root, int& sum) {
    if (!root) return;

    // Traverse right subtree first (largest elements)
    greaterSum(root->right, sum);

    sum += root->data;  // Maintain cumulative sum
    root->data = sum;   // Update current node

    // Traverse left subtree
    greaterSum(root->left, sum);
}

// Preorder traversal to display tree
void preOdr(Node* root) {
    if (!root) return;

    cout << root->data << ' ';
    preOdr(root->left);
    preOdr(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i]; // Sorted array input
    }

    Node* root = build(vec, 0, n - 1);
    int sum = 0;
    greaterSum(root, sum);

    preOdr(root); // Output preorder traversal of Greater Sum Tree
    return 0;
}

