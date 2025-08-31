// Calculates minimum cost to build libraries and roads in a graph using DFS on components

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t; // number of test cases
    while(t--) {
        int n, m; cin >> n >> m; // nodes and edges
        ll a, b; cin >> a >> b;  // cost of library and road
        vector<vector<int>> g(n + 1);

        for (int i = 0; i < m; i++) { 
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u); // undirected graph
        }

        vector<bool> vis(n + 1, false); 
        ll ans = 0;

        if (a <= b) ans = ll(n) * a; // build all libraries if cheaper
        else {
            for (int i = 1; i <= n; i++) {
                if (!vis[i]) {
                    ll compSize = 0;
                    stack<int> st;
                    st.push(i);
                    vis[i] = true;

                    while (!st.empty()) {
                        int u = st.top(); st.pop();
                        compSize++;
                        for (int v : g[u]) {
                            if (!vis[v]) {
                                vis[v] = true;
                                st.push(v); // DFS traversal
                            }
                        }
                    }
                    ans += a + (compSize - 1) * b; // cost for this component
                }
            }
        }
        cout << ans << endl; // total cost
    }
    return 0;
}
