#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;             // number of items
    int cap; cin >> cap;         // maximum capacity of knapsack

    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++) cin >> val[i]; // values of items
    for (int i = 0; i < n; i++) cin >> wt[i];  // weights of items

    // dp[j] = max value achievable with capacity j
    vector<int> dp(cap + 1, 0);

    // iterate over all items
    for (int i = 0; i < n; i++) {
        // loop backwards so each item is used at most once
        for (int j = cap; j >= wt[i]; j--) {
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]); 
        }
    }

    cout << dp[cap]; // maximum value achievable with given capacity
    return 0;
}
