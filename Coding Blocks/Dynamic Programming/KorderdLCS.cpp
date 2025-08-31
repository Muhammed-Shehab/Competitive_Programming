#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int k; cin >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    // dp[i][j][x] = LCS length for first i elements of a, first j elements of b,
    // with at most x modifications allowed
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int x = 0; x <= k; x++) {
                if (a[i - 1] == b[j - 1]) {
                    // match → extend
                    dp[i][j][x] = dp[i-1][j-1][x] + 1;
                } else {
                    // skip from one side
                    dp[i][j][x] = max(dp[i-1][j][x], dp[i][j-1][x]);
                    // use modification if available
                    if (x > 0) dp[i][j][x] = max(dp[i][j][x], 1 + dp[i-1][j-1][x-1]);
                }
            }
        }
    }

    cout << dp[n][m][k];
    return 0;
}
