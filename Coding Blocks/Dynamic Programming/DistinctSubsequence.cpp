#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7; 

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        vector<ll> dp(n + 1, 1);     // dp[i] = number of distinct subsequences of prefix length i
        vector<int> lst(256, -1);    // last occurrence of each character (ASCII)

        for (int i = 1; i <= n; i++) {
            // By default: each subsequence can either take or skip s[i-1]
            dp[i] = (2 * dp[i - 1]) % MOD;

            char c = s[i - 1];
            if (lst[c] != -1) {
                // If c appeared before, subtract overcounted subsequences
                dp[i] = (dp[i] - dp[lst[c] - 1] + MOD) % MOD;
            }

            lst[c] = i;  // update last occurrence
        }

        cout << dp[n] << endl;  // result for this test case
    }
    return 0;
}
