#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    stack<int> st;             // Stack to keep track of next greater candidates
    vector<int> res(n, -1);    // Result array, initialized with -1

    // Iterate twice the array length for circular effect
    for (int i = 2 * n - 1; i >= 0; i--) {
        int id = i % n;        // Actual index in the array

        // Pop elements smaller or equal to current element
        while (!st.empty() && st.top() <= vec[id]) st.pop();

        // Only store result in the first pass
        if (i < n && !st.empty()) res[id] = st.top();

        // Push current element for future comparisons
        st.push(vec[id]);
    }

    // Print the next greater elements for all positions
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    
    return 0;
}
