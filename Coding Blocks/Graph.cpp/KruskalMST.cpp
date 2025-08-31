// Kruskal's Minimum Spanning Tree implementation using Disjoint Set Union (Union-Find)
// Time Complexity: O(E log E) due to edge sorting
// Space Complexity: O(V + E)

#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union-Find) with path compression and union by rank
struct dsu {
    vector<int> parent, rank;

    dsu (int v) {
        rank.assign(v, 0);
        parent.resize(v);
        iota(parent.begin(), parent.end(), 0); // initialize parent[i] = i
    }

    int find (int x) { 
        if (parent[x] != x) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false; // already in same set
        if (rank[x] < rank[y]) swap(x, y); // union by rank
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

// Kruskal's algorithm to compute MST weight
int kruskal (int v, vector<array<int, 3>> &edges) {
    // sort edges by weight
    sort(edges.begin(), edges.end(), [](const array<int, 3> &a, const array<int, 3> &b) {
        return a[2] < b[2];
    });

    dsu ds(v);
    int mstw = 0, cnt = 0;

    for (auto &e : edges) {
        int u = e[0], x = e[1], w = e[2];
        if (ds.unite(u, x)) { // add edge if it connects two components
            mstw += w;
            cnt++;
        }
        if (v - 1 == cnt) break; // MST complete
    }
    return mstw;
}

int main() {
    int v, e; cin >> v >> e;
    vector<array<int, 3>> edges;

    for (int i = 0; i < e; i++) {
        int u, x, w; cin >> u >> x >> w;
        edges.push_back({u, x, w}); // store edges as {u, v, w}
    }

    cout << kruskal(v, edges) << endl; // print MST total weight
    return 0;
}

