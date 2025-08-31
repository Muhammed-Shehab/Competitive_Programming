#include<bits/stdc++.h>
using namespace std;

// Function to insert an element at the bottom of a stack
void insAtBottom(stack<int> &st, int &data) {
    if (st.empty()) {       // Base case: if stack is empty, push the data
        st.push(data);
        return;
    }
    int top = st.top();     // Store the top element
    st.pop();               // Remove it
    insAtBottom(st, data);  // Recursive call to insert data at bottom
    st.push(top);           // Push the top element back
}

// Function to reverse the stack using recursion
void revSt(stack<int> &st) {
    if (st.empty()) return;     // Base case: empty stack, nothing to reverse

    int top = st.top();         // Store top element
    st.pop();                   // Remove top
    revSt(st);                  // Reverse the remaining stack
    insAtBottom(st, top);       // Insert the removed top element at bottom
}

int main() {
    int n; cin >> n;            // Number of elements
    stack<int> st;
    int data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        st.push(data);          // Push elements into stack
    }

    revSt(st);                  // Reverse the stack

    // Print the reversed stack
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}

