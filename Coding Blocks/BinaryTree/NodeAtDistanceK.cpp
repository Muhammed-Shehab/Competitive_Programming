#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <algorithm>
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

// Build binary tree from preorder and inorder traversal
Node* build(vector<int>& preOdr, vector<int>& inOdr, int& preInd, int left, int right) {
    if (left > right) return nullptr;

    Node* root = new Node(preOdr[preInd]);

    int inInd;
    for (int i = left; i <= right; i++) {
        if (preOdr[preInd] == inOdr[i]) {
            inInd = i;
            break;
        }
    }
    preInd++;
    root->left = build(preOdr, inOdr, preInd, left, inInd - 1);
    root->right = build(preOdr, inOdr, preInd, inInd + 1, right);

    return root;
}

// Print all nodes at distance K from given root
void printSubNode(Node* root, int k, vector<int>& result) {
    if (!root || k < 0) return;

    if (k == 0) {
        result.push_back(root->data);
        return;
    }
    printSubNode(root->left, k - 1, result);
    printSubNode(root->right, k - 1, result);
}

// Find nodes at distance K from target node
int printAtK(Node* root, int target, int k, vector<int>& result) {
    if (!root) return -1;

    if (root->data == target) {
        printSubNode(root, k, result);
        return 0;
    }

    int dl = printAtK(root->left, target, k, result);
    if (dl != -1) {
        if (dl + 1 == k) result.push_back(root->data);
        else printSubNode(root->right, k - dl - 2, result);
        return dl + 1;
    }

    int dr = printAtK(root->right, target, k, result);
    if (dr != -1) {
        if (dr + 1 == k) result.push_back(root->data);
        else printSubNode(root->left, k - dr - 2, result);
        return dr + 1;
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> inOdr(n), preOdr(n);
    for (int i = 0; i < n; i++) cin >> preOdr[i];
    for (int i = 0; i < n; i++) cin >> inOdr[i];

    int preInd = 0;
    Node* root = build(preOdr, inOdr, preInd, 0, n - 1);

    int t;
    cin >> t;
    while (t--) {
        vector<int> result;
        int target, k;
        cin >> target >> k;
        printAtK(root, target, k, result);

        if (result.empty()) {
            cout << 0 << endl;
        } else {
            sort(result.begin(), result.end());
            for (int val : result) cout << val << ' ';
            cout << endl;
        }
    }

    return 0;
}
