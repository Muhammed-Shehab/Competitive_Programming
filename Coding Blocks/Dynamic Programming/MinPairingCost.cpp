#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
using ll = long long;

int main() {
    int n, m; 
    cin >> n >> m;                // Input number of boys and girls

    vector<int> boys(n), girls(m);
    for (int &i : boys) cin >> i; // Read skill/height/etc. for boys
    for (int &i : girls) cin >> i;// Read skill/height/etc. for girls

    // dp[i][j] = minimum cost of pairing first i boys with first j girls
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, LLONG_MAX));

    // Sort both arrays to minimize cost by matching closer values
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    // Base case: pairing 0 boys costs 0 regardless of girls
    for (int i = 0; i <= m; i++) dp[0][i] = 0;

    // Transition: decide to either pair boy i with girl j, or skip girl j
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= m; j++) {
            ll pairCost = dp[i-1][j-1] + abs(boys[i-1] - girls[j-1]); // take pair
            ll skipCost = dp[i][j-1];                                // skip girl j
            dp[i][j] = min(skipCost, pairCost);
        }
    }

    // Answer: minimum cost of pairing all n boys among m girls
    cout << dp[n][m];
    return 0;
}
