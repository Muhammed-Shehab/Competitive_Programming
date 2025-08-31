#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; 
    cin >> n;
    vector<ll> vec(n);
    
    // Read histogram heights
    for(ll i = 0; i < n; i++) cin >> vec[i];

    stack<ll> st;  // Stack to store indices
    ll maxArea = 0;  // Variable to keep track of maximum area

    for (ll i = 0; i <= n; i++) {
        ll curr = (i == n) ? 0 : vec[i]; // Sentinel 0 at end to empty stack
        // Pop elements from stack while current height is smaller
        while (!st.empty() && curr < vec[st.top()]) {
            ll top = st.top(); st.pop();
            ll width = (st.empty()) ? i : i - st.top() - 1;  // Width of rectangle
            maxArea = max(maxArea, width * vec[top]); // Update max area
        }
        st.push(i); // Push current index to stack
    }

    cout << maxArea;  // Output the result
    return 0;
}
