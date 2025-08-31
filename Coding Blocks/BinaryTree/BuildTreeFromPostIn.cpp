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

// Function to build binary tree from postorder and inorder traversals
Node* buildTree(vector<int>& postOdr, vector<int>& inOdr, int& postIdx, int left, int right) {
    if (left > right) return nullptr; // No nodes in this subtree

    // Create root from current postorder index
    Node* root = new Node(postOdr[postIdx]);

    // Find index of root in inorder traversal
    int inIdx;
    for (int i = right; i >= left; i--) {
        if (postOdr[postIdx] == inOdr[i]) {
            inIdx = i;
            break;
        }
    }

    postIdx--; // Move to next root in postorder

    // Recursively build right and left subtrees
    root->right = buildTree(postOdr, inOdr, postIdx, inIdx + 1, right);
    root->left  = buildTree(postOdr, inOdr, postIdx, left, inIdx - 1);

    return root;
}

// Function to display the tree in a readable format
void displayTree(Node* root) {
    if (!root) return;

    // Display left child
    if (root->left) cout << root->left->data;
    else cout << "END";

    // Display current node
    cout << " => " << root->data << " <= ";

    // Display right child
    if (root->right) cout << root->right->data;
    else cout << "END";

    cout << endl;

    // Recursively display subtrees
    if (root->left) displayTree(root->left);
    if (root->right) displayTree(root->right);
}

int main() {
    int n; 
    cin >> n;

    vector<int> postOdr(n), inOdr(n);

    // Input postorder
    for (int i = 0; i < n; i++) cin >> postOdr[i];

    // Input inorder
    for (int i = 0; i < n; i++) cin >> inOdr[i];

    int postIdx = n - 1; // Start from last index of postorder
    Node* root = buildTree(postOdr, inOdr, postIdx, 0, n - 1);

    // Display tree
    displayTree(root);

    return 0;
}
