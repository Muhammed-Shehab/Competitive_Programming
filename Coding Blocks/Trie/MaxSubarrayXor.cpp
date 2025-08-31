#include<iostream>
#include<algorithm>
using namespace std;

struct trieNode {
    trieNode *child[2]; 
    trieNode () {
        child[0] = child[1] = nullptr;
    }
};

struct trie {
    trieNode *root;
    trie () {
        root = new trieNode();
    }

    // insert 32-bit number into trie
    void insert (int val) {
        trieNode *node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (val >> i) & 1;
            if (!node->child[bit]) node->child[bit] = new trieNode();
            node = node->child[bit];
        }
    }

    // query best XOR value with val
    int query (int val) {
        trieNode *node = root;
        int best = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (val >> i) & 1;
            if (node->child[bit ^ 1]) { 
                best |= (1 << i);         // take opposite bit for maximizing XOR
                node = node->child[bit ^ 1];
            } else {
                node = node->child[bit];  // fallback if opposite not available
            }
        }
        return best;
    }
};

int main() {
    int n; cin >> n;
    trie Trie;
    Trie.insert(0);              // base prefix = 0

    int prefix = 0, maxXor = 0;
    while (n--) {
        int a; cin >> a;
        prefix ^= a;                              // running prefix XOR
        maxXor = max(maxXor, Trie.query(prefix)); // best XOR subarray till now
        Trie.insert(prefix);
    }
    cout << maxXor;
    return 0;
}
