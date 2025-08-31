#include <iostream>
#include <queue>
using namespace std;

/*
Problem: Check if a binary tree is height-balanced.
A binary tree is height-balanced if for every node, the height difference
between its left and right subtrees is at most 1.

Approach:
1. Build tree recursively from input:
   - "true" indicates a node exists, followed by its value
   - Then recursively read left and right children if "true"
2. Check height balance in a single traversal:
   - Recursive function returns a pair: {height, isBalanced}
   - height = max(height of left, height of right) + 1
   - isBalanced = abs(leftHeight - rightHeight) <= 1 && leftBalanced && rightBalanced

Time Complexity: O(n) for n nodes (each node visited once)
Space Complexity: O(height of tree) due to recursion
*/

// Node structure for binary tree
class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive tree builder from input
node *build(string s) {
    if (s == "true") {
        int d;
        cin >> d;
        node *root = new node(d);

        string l;
        cin >> l;
        if (l == "true") {
            root->left = build(l);
        }

        string r;
        cin >> r;
        if (r == "true") {
            root->right = build(r);
        }

        return root;
    }
    return nullptr;
}

// Optimized height-balanced check: returns {height, isBalanced}
pair<int,bool> isHeightBalancedOptimised(node *root) {
    if (!root) return {0, true};

    auto left = isHeightBalancedOptimised(root->left);
    auto right = isHeightBalancedOptimised(root->right);

    int height = max(left.first, right.first) + 1;
    bool balanced = abs(left.first - right.first) <= 1 && left.second && right.second;

    return {height, balanced};
}

int main() {
    // Build tree from input
    node *root = build("true");

    // Check and print if tree is height-balanced
    cout << boolalpha << isHeightBalancedOptimised(root).second;

    return 0;
}
