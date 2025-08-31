// BFS for shortest reach in an undirected graph with constant edge weight

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int q; cin >> q; // number of test cases
    while (q--) {
        int n, m; cin >> n >> m; // nodes and edges
        vector<vector<int>> g(n + 1); // adjacency list
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u); // undirected edges
        }

        vector<int> dis(n + 1, -1); // distance from source, -1 = unreachable
        queue<int> bfs;
        int s; cin >> s; // source node
        dis[s] = 0;
        bfs.push(s);

        while (!bfs.empty()) {
            int u = bfs.front(); bfs.pop();
            for (int v : g[u]) {
                if (dis[v] == -1) { // unvisited
                    dis[v] = dis[u] + 6; // edge weight = 6
                    bfs.push(v); // enqueue
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i == s) continue;
            cout << dis[i] << ' '; // print distances
        }
        cout << endl;
    }
    return 0;
}
