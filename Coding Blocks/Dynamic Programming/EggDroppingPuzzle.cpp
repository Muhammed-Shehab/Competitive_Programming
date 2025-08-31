#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t; // number of test cases
    
    while (t--) {
        int k, n; 
        cin >> k >> n; // k = eggs, n = floors

        // dp[i][m] = maximum number of floors that can be tested 
        // with i eggs and m moves
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        int m = 0; // minimum moves required
        // keep increasing moves until we can cover at least n floors
        while (dp[k][m] < n) {
            m++;
            for (int i = 1; i <= k; i++) {
                // recurrence relation:
                // dp[i][m] = 1 (current floor) 
                //           + dp[i-1][m-1] (egg breaks, check below) 
                //           + dp[i][m-1]   (egg survives, check above)
                dp[i][m] = dp[i - 1][m - 1] + dp[i][m - 1] + 1;
            }
        }
        cout << m << endl; // answer = minimum number of moves
    }
    
    return 0;
}
