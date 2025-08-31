#include <iostream>
#include <vector>
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

// Build binary tree from input stream with "true"/"false" flags for children
Node* build(istringstream& ss) {
    int val;
    ss >> val;
    Node* root = new Node(val);

    string leftflag, rightflag;
    ss >> leftflag;
    if (leftflag == "true") root->left = build(ss);
    ss >> rightflag;
    if (rightflag == "true") root->right = build(ss);
    return root;
}

// Function to print all root-to-leaf paths with sum = k
void printPaths(Node* root, int sum, int k, vector<Node*>& path) {
    if (!root) return;

    sum += root->data;
    path.push_back(root);

    // If leaf node and path sum equals k, print path
    if (!root->left && !root->right && sum == k) {
        for (Node* node : path) cout << node->data << ' ';
        cout << endl;
    }

    // Recurse to left and right subtrees
    printPaths(root->left, sum, k, path);
    printPaths(root->right, sum, k, path);

    path.pop_back(); // Backtrack
}

int main() {
    string input;
    getline(cin, input);
    istringstream ss(input);
    Node* root = build(ss);

    int k; 
    cin >> k;

    vector<Node*> path;
    printPaths(root, 0, k, path);

    return 0;
}
