#include<iostream>
#include<vector> 
using namespace std;

struct trieNode {
	trieNode *child[2];
	trieNode() {
		child[0] = child[1] = nullptr;
	}
};

struct trie {
	trieNode *root;
	trie() {
		root = new trieNode();
	}

	// insert number into binary trie
	void insert (int num) {
		trieNode *node = root;
		for (int i = 30; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if (!node->child[bit]) node->child[bit] = new trieNode();
			node = node->child[bit];
		}
	}

	// query max XOR with given number
	int maxXor (int num) {
		trieNode *node = root;
		int ans = 0;
		for (int i = 30; i >= 0; i--) {
			int bit = (num >> i) & 1;
			int opp = bit ^ 1;
			if (node->child[opp]) { // prefer opposite bit if exists
				ans |= (1 << i);
				node = node->child[opp];
			} else {
				node = node->child[bit];
			}
		}
		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<int> vec(n+1,0);
	for (int i = 1; i <= n; i++) cin >> vec[i];

    // prefix XOR
    vector<int> pre(n+1, 0);
    for (int i = 1; i <= n; i++) pre[i] = pre[i-1] ^ vec[i];

    // suffix XOR
    vector<int> suf(n+2, 0);
    for (int i = n; i >= 1; i--) suf[i] = suf[i+1] ^ vec[i];

	// left[i] = max subarray XOR in [1..i]
	vector<int> left(n+1, 0);
	{
		trie Trie;
		Trie.insert(0);
		for (int i = 1; i <= n; i++) {
			int maxHere = Trie.maxXor(pre[i]);
			left[i] = max(maxHere, left[i - 1]);
			Trie.insert(pre[i]);
		}
	}

	// right[i] = max subarray XOR in [i..n]
	vector<int> right(n+1, 0);
	{
		trie Trie;
		Trie.insert(0);
		for (int i = n; i >= 1; i--) {
			int maxHere = Trie.maxXor(suf[i]);
			right[i] = max(maxHere, right[i + 1]);
			Trie.insert(suf[i]);
		}
	}

	// combine: best split into [1..i] and [i+1..n]
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, left[i] + right[i + 1]);
	}
	cout << ans;
	return 0;
}
