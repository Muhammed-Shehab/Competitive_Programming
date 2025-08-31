#include <bits/stdc++.h>
using namespace std;

// Function to compute Next Greater Element to the right
// Time Complexity: O(n), Space Complexity: O(n)
vector<long long> nGE(vector<long long> vec, int n) {
    vector<long long> res(n, -1); // Initialize result with -1
    stack<int> st; // Stack to maintain candidates

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements smaller or equal to current
        while (!st.empty() && st.top() <= vec[i]) st.pop();

        // If stack is not empty, top is next greater
        if (!st.empty()) res[i] = st.top();

        // Push current element as potential NGE for left elements
        st.push(vec[i]);
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<long long> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    vector<long long> res = nGE(vec, n);

    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    return 0;
}
