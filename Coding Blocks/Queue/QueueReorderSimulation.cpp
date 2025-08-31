#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    int n; 
    cin >> n;  // Number of people in the queue

    int d;
    int step = 0;  // Count the number of steps (push/pop operations)
    queue<int> q;

    // Read initial queue
    int m = n;
    while(m--) {
        cin >> d;
        q.push(d);
    }

    vector<int> vec(n);
    // Read desired order
    for (int i = 0; i < n; i++) cin >> vec[i];

    int i = 0; 
    // Simulate queue operations
    while (!q.empty()) {
        if (vec[i] == q.front()) {
            // Person is in correct position
            i++;
            q.pop();
            step++;  // Count the step
        } else {
            // Move front person to the back
            q.push(q.front());
            q.pop();
            step++;  // Count the step
        }
    }

    cout << step;  // Output total steps
    return 0;
}
