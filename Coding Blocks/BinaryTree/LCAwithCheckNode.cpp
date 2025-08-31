#include <iostream>
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

// Helper function to find LCA and mark if n1 and n2 are found
Node* lcaNode(Node* root, int n1, int n2, bool &l1, bool &l2) {
    if (!root) return nullptr;

    if (root->data == n1) { l1 = true; return root; }
    if (root->data == n2) { l2 = true; return root; }

    Node* leftlca  = lcaNode(root->left, n1, n2, l1, l2);
    Node* rightlca = lcaNode(root->right, n1, n2, l1, l2);

    if (leftlca && rightlca) return root;
    return leftlca ? leftlca : rightlca;
}

// Check if a given node exists in subtree
bool check(Node* root, int n) {
    if (!root) return false;
    if (root->data == n) return true;
    return check(root->left, n) || check(root->right, n);
}

// Function to find LCA with additional node existence checks
Node* LCA(Node* root, int n1, int n2) {
    bool l1 = false, l2 = false;
    Node* lca = lcaNode(root, n1, n2, l1, l2);

    // Ensure both nodes exist in tree
    if ((l1 && l2) || (l1 && check(lca, n2)) || (l2 && check(lca, n1))) 
        return lca;

    return nullptr;
}

int main() {
    string input; 
    getline(cin, input);
    istringstream ss(input);
    Node* root = build(ss);

    int n1, n2; 
    cin >> n1 >> n2;

    Node* ans = LCA(root, n1, n2);
    if(ans) cout << ans->data;
    else cout << "No LCA found";

    return 0;
}
