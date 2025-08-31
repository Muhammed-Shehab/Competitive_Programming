#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string a, b; 
    cin >> a >> b;   // input two strings

    int n = a.size();
    int m = b.size();

    // dp[i][j] = length of LCS between a[0..i-1] and b[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;  // match → extend LCS
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // skip from one string
        }
    }

    // Reconstruct LCS string from dp table
    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);  // character is part of LCS
            i--; j--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) 
            i--;  // move up in dp table
        else 
            j--;  // move left in dp table
    }

    reverse(lcs.begin(), lcs.end());  // we built it backwards
    cout << lcs;

    return 0;
}
