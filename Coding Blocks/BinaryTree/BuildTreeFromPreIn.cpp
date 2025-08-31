#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

// Function to build binary tree from preorder and inorder traversals
Node* buildTree(vector<int> &preOdr, vector<int> &inOdr, int &preIdx, int left, int right) {
    if (left > right) return nullptr; // Base case: no elements to construct

    // Create root from current preorder element
    Node *root = new Node(preOdr[preIdx]);

    // Find index of root in inorder array
    int inIdx;
    for (int i = left; i <= right; i++) {
        if (preOdr[preIdx] == inOdr[i]) {
            inIdx = i;
            break;
        }
    }

    preIdx++; // Move to next preorder element
    // Recursively build left and right subtrees
    root->left = buildTree(preOdr, inOdr, preIdx, left, inIdx - 1);
    root->right = buildTree(preOdr, inOdr, preIdx, inIdx + 1, right);

    return root;
}

// Function to perform level-order traversal and print nodes
void levelOrderTraversal(Node *root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> preOdr(n), inOdr(n);
    for (int i = 0; i < n; i++) cin >> preOdr[i]; // Preorder input
    for (int i = 0; i < n; i++) cin >> inOdr[i];  // Inorder input

    int preIdx = 0;
    Node *root = buildTree(preOdr, inOdr, preIdx, 0, n - 1);

    levelOrderTraversal(root); // Print level-order traversal
    return 0;
}
