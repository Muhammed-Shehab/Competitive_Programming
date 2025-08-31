#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

/*
Problem: Level Order Traversal of a Binary Tree
- Given a binary tree, return a 2D vector of integers representing
  the values at each level.
- Input is given in a specific format using a single line string:
  node value, followed by "true"/"false" flags for left/right existence.

Approach:
1. Build tree recursively using istringstream:
   - Read node value
   - Read left and right flags ("true" => build subtree, "false" => nullptr)
2. Perform level order traversal using a queue:
   - Push root initially
   - While queue is not empty:
       - Process all nodes at current level (queue size)
       - Push children into queue
       - Save level values in a 2D vector

Time Complexity: O(n) for n nodes
Space Complexity: O(n) for queue and result storage
*/

// Node structure for binary tree
struct node {
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive tree builder from input string stream
node* build(istringstream &ss) {
    int val;
    if (!(ss >> val)) return nullptr;

    node *root = new node(val);

    string leftflag, rightflag;
    ss >> leftflag;
    if (leftflag == "true") root->left = build(ss);

    ss >> rightflag;
    if (rightflag == "true") root->right = build(ss);

    return root;
}

// Function to perform level order traversal
vector<vector<int>> levelOrder(node *root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            node *curr = q.front();
            q.pop();

            level.push_back(curr->data);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        result.push_back(level);
    }

    return result;
}

int main() {
    string input;
    getline(cin, input);

    istringstream ss(input);
    node *root = build(ss);

    vector<vector<int>> vec = levelOrder(root);

    // Print result in formatted 2D vector style
    cout << '[';
    for (int i = 0; i < vec.size(); i++) {
        cout << '[';
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j];
            if (j != vec[i].size() - 1) cout << ", ";
        }
        cout << ']';
        if (i != vec.size() - 1) cout << ", ";
    }
    cout << ']';

    return 0;
}
