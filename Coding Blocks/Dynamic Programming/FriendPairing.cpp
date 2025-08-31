#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int t; 
    cin >> t;  // number of test cases

    // dp[i] = number of ways to pair up i friends
    // Base cases:
    // dp[1] = 2 (friend alone, or pair with one more if allowed by context)
    // dp[2] = 3 (both alone, pair together, or each separate)
    vector<ll> dp(91); 
    dp[1] = 2;  
    dp[2] = 3;

    // recurrence: dp[n] = dp[n-1] + dp[n-2]
    // Explanation:
    // - If nth friend stays single => dp[n-1]
    // - If nth friend pairs with one => dp[n-2]
    for (int i = 3; i < 91; i++) 
        dp[i] = dp[i - 1] + dp[i - 2];

    // Answer queries
    while (t--) {
        int n; 
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
