#include <iostream>
#include <queue>
using namespace std;

int main() {
    int q, k;
    cin >> q >> k;

    // Max-heap to store k smallest distances
    priority_queue<long long> maxHeap;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x, y;
            cin >> x >> y;

            // Compute squared distance from origin
            long long dist = x * x + y * y;

            if (maxHeap.size() < k) {
                // If heap not full, just push
                maxHeap.push(dist);
            } else if (dist < maxHeap.top()) {
                // If new distance smaller than largest in heap
                maxHeap.pop();
                maxHeap.push(dist);
            }
        } else if (type == 2) {
            // Output the largest distance among current k closest points
            cout << maxHeap.top() << endl;
        }
    }
    return 0;
}
