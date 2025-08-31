#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
using ll = long long;

unordered_map<ll,ll> mp;  // memoization table

// recursive function to compute max coin exchange value
ll maxi (ll n) {
    if (n < 12) return n;  // base case: not profitable to exchange

    auto it = mp.find(n);  
    if(it != mp.end()) return it->second;  // return cached value if exists

    // try exchanging into n/2, n/3, n/4
    ll frac = maxi(n / 2) + maxi(n/3) + maxi(n/4);

    // store and return the best result
    return mp[n] = max(n, frac);
}

int main() {
    ll n; cin >> n;            // input coin value
    cout << maxi(n);           // output maximum possible exchange
    return 0;
}
