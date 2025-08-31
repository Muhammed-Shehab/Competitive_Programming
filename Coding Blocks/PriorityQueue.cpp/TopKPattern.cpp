#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    Problem: Find the Kth Largest Element in an Array
    Approach: Min-Heap (Priority Queue)

    Idea:
    - Maintain a min-heap of size K.
    - Push each element into heap.
    - If heap size exceeds K, pop the smallest element.
    - After processing all elements, the top of heap = Kth largest.

    Why Min-Heap?
    - Because it efficiently maintains the top K largest elements,
      discarding smaller ones.
    - Heap size is always <= K.

    Complexity:
    - For N elements:
        -> Each push/pop takes O(log K).
        -> Total = O(N log K).
    - Space: O(K) for heap.

*/

int kthLargest(vector<int>& vec, int k) {
    // Min-heap to store K largest elements
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (int val : vec) {
        minHeap.emplace(val);
        if ((int)minHeap.size() > k) {
            minHeap.pop(); // remove smallest to keep only K elements
        }
    }
    return minHeap.top(); // Kth largest element
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    cout << kthLargest(vec, k);
    return 0;
}
