// Dijkstra's algorithm: shortest distance from source in weighted undirected graph

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s; 
    cin >> n >> m >> s; // nodes, edges, source
    vector<vector<pair<int, int>>> g(n); // adjacency list: {neighbor, weight}

    for (int i = 0; i < m; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w}); // undirected graph
    }

    const long long inf = LLONG_MAX;
    vector<long long> dist(n, inf); // distance from source
    dist[s] = 0;

    using p = pair<long long, int>;
    priority_queue<p, vector<p>, greater<p>> pq; // min-heap
    pq.push({0, s});

    while (!pq.empty()) {
        auto newn = pq.top();
        long long d = newn.first;
        int u = newn.second;
        pq.pop();

        if (d != dist[u]) continue; // stale entry

        for (auto edge : g[u]) {
            int v = edge.first;
            int w = edge.second;
            if (d + w < dist[v]) { 
                dist[v] = d + w; // relax
                pq.push({d + w, v});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << (dist[i] == inf ? -1 : dist[i]); // output distance
    }
    cout << '\n';

    return 0;
}
