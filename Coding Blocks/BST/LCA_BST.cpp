#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

Node* findLCA(Node* root, int a, int b) {
    if (!root) return nullptr;

    if (a < root->data && b < root->data)
        return findLCA(root->left, a, b);
    else if (a > root->data && b > root->data)
        return findLCA(root->right, a, b);
    else
        return root;
}

int main() {
    int N;
    cin >> N;
    Node* root = nullptr;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int a, b;
    cin >> a >> b;

    Node* lca = findLCA(root, a, b);
    if (lca)
        cout << lca->data << endl;
    return 0;
}