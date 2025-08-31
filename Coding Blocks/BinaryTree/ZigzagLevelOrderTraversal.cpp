#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Function to build a binary tree from input stream in the "val true/false true/false ..." format
Node* build(istringstream &ss) {
    int val;
    if (!(ss >> val)) return nullptr;

    Node *root = new Node(val);
    string leftflag, rightflag;
    
    ss >> leftflag;
    if (leftflag == "true") root->left = build(ss);

    ss >> rightflag;
    if (rightflag == "true") root->right = build(ss);

    return root;
}

// Function to perform standard level order traversal and store each level in a vector
vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            Node *curr = q.front();
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
    Node *root = build(ss);

    vector<vector<int>> vec = levelOrder(root);

    // Print in Zig-Zag / Spiral order
    for (int i = 0; i < vec.size(); i++) {
        if ((i & 1) == 0) { // Even levels -> left to right
            for (int j = 0; j < vec[i].size(); j++) {
                cout << vec[i][j] << " ";
            }
        } else { // Odd levels -> right to left
            for (int j = vec[i].size() - 1; j >= 0; j--) {
                cout << vec[i][j] << " ";
            }
        }
    }

    return 0;
}
