#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    stack<int> st; // Stack stores indices

    vector<int> res(n); // Result vector for span

    for (int i = 0; i < n; i++) {
        // Pop elements smaller or equal to current
        while (!st.empty() && vec[st.top()] <= vec[i]) {
            st.pop();
        }

        // If stack empty, span = i + 1, else span = i - index of previous greater
        res[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // Push current index as potential previous greater for next elements
        st.push(i); 
    }

    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    cout << "END"; // Optional marker for end of output
    return 0;
}
