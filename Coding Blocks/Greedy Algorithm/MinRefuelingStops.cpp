#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct stops {
    int unit, dis; // unit = fuel available, dis = distance from town
};

int main() {
    int n; 
    cin >> n;
    vector<stops> vec(n + 1);

    // Read stops: distance from town & fuel available
    for (int i = 0; i < n; i++) {
        cin >> vec[i].dis >> vec[i].unit;
    }

    int l, p; 
    cin >> l >> p;  // l = distance to town, p = initial fuel

    // Add final "stop" at town with 0 fuel
    vec[n] = {0, 0};
    n++;

    // Convert distances: store as distance from starting point
    for (int i = 0; i < n; i++) vec[i].dis = l - vec[i].dis;

    // Sort stops by distance from start
    sort(vec.begin(), vec.end(), [](stops a, stops b) {
        return a.dis < b.dis;
    });

    int fuel = p, ans = 0, prev = 0;
    priority_queue<int> pq; // max-heap for fuel

    for (int i = 0; i < n; i++) {
        int dist = vec[i].dis - prev; // distance to next stop
        fuel -= dist;

        // Refuel from previous stations until enough to reach current stop
        while (fuel < 0 && !pq.empty()) {
            fuel += pq.top();
            pq.pop();
            ans++;
        }

        // If still not enough fuel → impossible
        if (fuel < 0) {
            cout << -1 << endl;
            return 0;
        }

        // Push current stop’s fuel into heap (option to refuel later)
        pq.push(vec[i].unit);
        prev = vec[i].dis;
    }

    cout << ans << endl;
    return 0;
}
