#include <iostream>
#include <queue>
#include <sstream>
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

// Build binary tree from level order input
// Uses -1 to indicate NULL child
Node* build(istringstream& ss) {
    int val;
    ss >> val;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        if (!(ss >> leftVal)) break;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        if (!(ss >> rightVal)) break;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

// Print the right view of a binary tree
void rightView(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            // Print the last node of current level
            if (i == size - 1) cout << curr->data << ' ';

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

int main() {
    string input;
    getline(cin, input);
    istringstream ss(input);

    Node* root = build(ss);
    rightView(root);

    return 0;
}
