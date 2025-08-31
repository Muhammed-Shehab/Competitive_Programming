#include<iostream>
#include<vector>
#include<climits>
using namespace std;
using ll = long long;

// Function to compute minimum cost to fill exactly weight 'w'
ll sol (ll w, vector<int> &vec, vector<int> &dp) {
    dp[0] = 0; // Base case: cost of filling weight 0 is 0

    // Loop over all possible weights from 1 to w
    for (int i = 1; i <= w; i++) {
        // Try all possible piece sizes j that can contribute to weight i
        for (int j = 1; j <= i; j++) {
            if (vec[j] != -1) { // Only consider available pieces
                // Transition: take piece of size j, add its cost
                dp[i] = min(dp[i], dp[i - j] + vec[j]);
            }
        }
    }

    // If dp[w] was never updated, return -1 (not possible)
    return (dp[w] == INT_MAX) ? -1 : dp[w];
}

int main() {
    int w, n;
    cin >> n >> w; // n = number of different packet sizes, w = required weight

    vector<int> vec(w + 1);      // vec[i] = cost of packet of weight i
    vector<int> dp(w + 1, INT_MAX); // dp[i] = min cost to get weight i

    for (int i = 1; i <= w; i++) cin >> vec[i]; // Input costs

    cout << sol(w, vec, dp); // Print result
    return 0;
}
