#include<iostream>
#include<map>
using namespace std;

// Node of Trie
struct trieNode {
    map<char, trieNode*> children; // stores all next characters
    bool isEnd;                    // marks end of a word
    trieNode () {
        isEnd = false;
    }
};

// Trie data structure
struct Trie {
    trieNode *root;
    Trie () {
        root = new trieNode();
    }

    // Insert word into trie
    void insert (const string &word) {
        trieNode *node = root;
        for (char ch : word) {
            if (!node->children[ch]) {
                node->children[ch] = new trieNode(); // create new path
            }
            node = node->children[ch];
        }
        node->isEnd = true; // mark word end
    }

    // Search prefix in trie, return node pointer if prefix exists
    bool search (trieNode* &node, string query) {
        node = root;
        for (char ch : query) {
            if (!node->children[ch]) return false; // prefix not found
            node = node->children[ch];
        }
        return true;
    }

    // DFS to print all words from a given node
    void dfs (trieNode* &node, string &prefix) {
        if (node->isEnd) {
            cout << prefix << endl;
        }
        for (auto &p : node->children) {
            prefix.push_back(p.first);
            dfs(p.second, prefix);
            prefix.pop_back(); // backtrack
        }
    }
};

int main() {
    int n; cin >> n;
    Trie trie;

    // Insert all dictionary words
    while (n--) {
        string s; cin >> s;
        trie.insert(s);
    }

    int q; cin >> q;
    while(q--) {
        string query; cin >> query;
        trieNode *node;

        // If prefix exists → print all suggestions
        if (trie.search(node, query)) {
            string prefix = query;
            trie.dfs(node, prefix);
        } 
        // Otherwise → say no suggestion and add new word
        else {
            cout << "No suggestions" << endl;
            trie.insert(query);
        }
    }
    return 0;
}
