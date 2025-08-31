#include <iostream>
#include <sstream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

// Function to build a binary tree from a stringstream input
Node* build(istringstream& ss) {
    int val;
    if (!(ss >> val)) return nullptr;  // End of input or invalid

    Node* root = new Node(val);

    string leftFlag, rightFlag;
    ss >> leftFlag;
    if (leftFlag == "true") root->left = build(ss);  // Recursively build left subtree

    ss >> rightFlag;
    if (rightFlag == "true") root->right = build(ss); // Recursively build right subtree

    return root;
}

// Function to print nodes that are single children (nodes with exactly one child)
void print(Node* root) {
    if (!root) return;

    // If node has only right child
    if (!root->left && root->right) cout << root->right->data << " ";

    // If node has only left child
    if (!root->right && root->left) cout << root->left->data << " ";

    // Recurse on left and right children
    if (root->left) print(root->left);
    if (root->right) print(root->right);
}

int main() {
    string input;
    getline(cin, input);  // Read entire tree input
    istringstream ss(input);

    Node* root = build(ss);  // Build the binary tree

    print(root);  // Print all single child nodes
    return 0;
}
