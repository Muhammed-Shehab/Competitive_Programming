#include<bits/stdc++.h>
using namespace std;

// Helper function to check if person i knows person j
bool verify(vector<vector<int>> &mat, int i, int j) {
    return mat[i][j] == 1;
}

int main() {
    int n; 
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    stack<int> s;

    // Push all people onto the stack and read the matrix
    for (int i = 0; i < n; i++) {
        s.push(i);
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    // Reduce stack to find a potential celebrity
    while (s.size() > 1) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();

        // If a knows b, a cannot be celebrity, keep b
        if (verify(mat, a, b)) s.push(b);
        // Else b cannot be celebrity, keep a
        else s.push(a);
    }

    int cand = s.top();  // Candidate for celebrity

    // Verify candidate
    for (int i = 0; i < n; i++) {
        if (i != cand) {
            // Candidate should not know anyone and everyone should know candidate
            if (verify(mat, cand, i) || !verify(mat, i, cand)) {
                cout <<  "No Celebrity";
                return 0;
            }
        }
    }

    cout << cand;  // Print celebrity index

    return 0;
}
