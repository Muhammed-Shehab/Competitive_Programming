#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    int val;
    stack<int> st; // Stack to store even-numbered codes

    while (n--) {
        cin >> val;
        if ((val & 1) == 1) { // Odd → pop and print
            if (!st.empty()) {
                cout << st.top() << endl;
                st.pop();
            } else {
                cout << "No Code" << endl; // Stack empty
            }
        } else { // Even → push into stack
            cin >> val;
            st.push(val);
        }
    }
    return 0;
}
