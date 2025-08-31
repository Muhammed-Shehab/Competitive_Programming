#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int t; 
    cin >> t;                        // number of queries
    
    vector<ll> query(t);
    ll maxi = 0;

    // Read all queries and find maximum index required
    for (ll &x : query) {
        cin >> x;
        maxi = max(x, maxi);
    }

    // Pointers for multiples of 2, 3, and 5
    ll i2 = 0, i3 = 0, i5 = 0;
    ll nxt2 = 2, nxt3 = 3, nxt5 = 5;

    vector<ll> ugly(maxi, 0);
    ugly[0] = 1;                     // First ugly number is always 1

    // Generate ugly numbers up to maxi
    for (ll i = 1; i < maxi; i++) {
        ll nxt = min(nxt2, min(nxt3, nxt5));
        ugly[i] = nxt;

        // Update pointers and next multiples
        if (nxt == nxt2) { i2++; nxt2 = ugly[i2] * 2; }
        if (nxt == nxt3) { i3++; nxt3 = ugly[i3] * 3; }
        if (nxt == nxt5) { i5++; nxt5 = ugly[i5] * 5; }
    }

    // Answer queries
    for (int i = 0; i < t; i++) {
        cout << ugly[query[i] - 1] << "\n";
    }
    return 0;
}
