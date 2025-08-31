// Count Islands in a Grid
// Approach: DFS with 8-directional movement
// Time Complexity: O(N*N)
// Space Complexity: O(N*N) for visited array + recursion stack


#include <iostream>
#include <vector>
using namespace std;

int n; // size of the grid
vector<vector<int>> grid; // grid input
vector<vector<bool>> vis; // visited array for DFS

// directions for 8 neighboring cells (horizontal, vertical, diagonal)
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};

// check if a cell is within bounds
bool valid(int x, int y) {
    return (x < n && y < n && x >= 0 && y >= 0);
}

// DFS to mark all connected 1s starting from (x, y)
void dfs(int x, int y) {
    vis[x][y] = true;
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] == 1)
            dfs(nx, ny);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        grid.assign(n, vector<int>(n));
        vis.assign(n, vector<bool>(n, false));

        // input the grid
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        int cnt = 0; // number of islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j);
                    cnt++; // found a new island
                }
            }
        }
        cout << cnt << endl;
    }
}
