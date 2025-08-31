#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minJumps(vector<int>& arr, int n) {
    if (n <= 1) return 0;              // already at the end
    if (arr[0] == 0) return INT_MAX;   // can't move anywhere

    int maxReach = arr[0];  // farthest index we can reach
    int steps = arr[0];     // steps left in current jump
    int jumps = 1;          // we are using first jump

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps;  // reached end

        maxReach = max(maxReach, i + arr[i]);
        steps--;

        // if no steps left → must jump again
        if (steps == 0) {
            jumps++;
            if (i >= maxReach) return INT_MAX; // stuck
            steps = maxReach - i;
        }
    }
    return INT_MAX;  // unreachable
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        int ans = minJumps(arr, n);
        if (ans == INT_MAX) cout << "Infinity" << endl;
        else cout << ans << endl;
    }
    return 0;
}
