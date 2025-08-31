#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main () {
    int k, n; cin >> n >> k; 
    // Read size of arrays and position k
    
    vector<ll> a(n), b(n);
    for (ll &x : a) cin >> x;   // Input array a
    for (ll &x : b) cin >> x;   // Input array b

    sort(a.begin(), a.end(), greater<ll>());  
    // Sort a in descending order

    ll sumitBase = a[k - 1];  
    // Take k-th largest element of a

    auto itMax = max_element(b.begin(), b.end());  
    ll maxE = *itMax;  
    ll sumitMax = sumitBase + maxE;  
    // Max element from b + base element from a

    b.erase(itMax);  
    // Remove chosen max element from b

    sort(b.begin(), b.end());  
    // Sort b in ascending order

    // Remove the base element from a
    for (int i = 0; i < n; i++) {
        if (a[i] == sumitBase) {
            a.erase(a.begin() + i);
            break;
        }
    }

    // Transform values of a with (sumitMax - a[i])
    for (int i = 0; i < n - 1; i++) {
        a[i] = sumitMax - a[i];
    }

    sort(a.begin(), a.end());  
    // Sort transformed a

    int i = 0, j = 0, match = 0;
    int m = b.size(); 
    n = a.size();

    // Two pointer matching between a and b
    while (i < n && j < m) {
        if (b[j] <= a[i]) {
            match++;
            i++; j++;
        } else {
            i++;
        }
    }

    cout << n - match + 1;  
    // Final result
    return 0;
}
