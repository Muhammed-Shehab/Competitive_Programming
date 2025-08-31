#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;   // Large prime to avoid overflow in counting

int main() {
    int t; 
    cin >> t;                      // number of test cases
    
    while (t--) {
        int n; 
        cin >> n;                  // number of coin types
        vector<ll> vec(n);
        
        // Input all coin denominations
        for (ll &x : vec) cin >> x;
        
        ll cent; 
        cin >> cent;               // target sum (amount to form)
        
        // dp[i] = number of ways to form sum i
        vector<ll> dp(cent + 1, 0);
        dp[0] = 1;                 // Base: only 1 way to form sum 0 (choose nothing)

        // Process each coin (order matters → combinations, not permutations)
        for (ll c : vec) {
            for (ll i = c; i <= cent; i++) {
                dp[i] = (dp[i] + dp[i - c]) % MOD;
            }
        }

        // Answer for target sum
        cout << dp[cent] << endl;
    }

    return 0;
}
