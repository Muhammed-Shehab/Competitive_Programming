#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> vec(n);
    for (ll &x : vec) cin >> x;

    // dp[i][j] = maximum value first player can secure from subarray [i...j]
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    // Base cases
    for (int i = 0; i < n; i++) dp[i][i] = vec[i];
    for (int i = 0; i < n - 1; i++) dp[i][i+1] = max(vec[i], vec[i+1]);

    // Fill DP for increasing lengths
    for (int len = 2; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            int j = i + len;
            dp[i][j] = max(
                vec[i] + min(dp[i+2][j], dp[i+1][j-1]),
                vec[j] + min(dp[i+1][j-1], dp[i][j-2])
            );
        }
    }

    cout << dp[0][n-1]; // Answer: max value first player can guarantee
    return 0;
}
