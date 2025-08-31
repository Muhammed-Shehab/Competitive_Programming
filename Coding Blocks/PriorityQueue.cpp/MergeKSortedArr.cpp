#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

/*
    Problem: Merge K Sorted Arrays into a single sorted output
    Approach: Min-Heap (Priority Queue)

    Each element pushed into heap is a tuple: (value, arrayIndex, elementIndex)
    - value      : actual integer from array
    - arrayIndex : identifies which array this value belongs to
    - elementIndex: index inside that array

    Steps:
    1. Push first element of every array into min-heap.
    2. Extract min element, print it, then push the next element from same array.
    3. Continue until heap is empty.

    Complexity:
    - Heap size at most K (number of arrays).
    - Each push/pop = O(log K).
    - For total N*K elements → O(N*K log K).
*/

void mergeKsorted(vector<vector<int>>& arrays, int k) {
    using t = tuple<int, int, int>; // (value, array index, element index)
    priority_queue<t, vector<t>, greater<>> minHeap;

    // Step 1: Push first element of each array into minHeap
    for (int i = 0; i < k; i++) {
        if (!arrays[i].empty()) {
            minHeap.emplace(arrays[i][0], i, 0);
        }
    }

    // Step 2: Extract min and push next from same array
    while (!minHeap.empty()) {
        auto [val, arrIdx, elemIdx] = minHeap.top();
        minHeap.pop();

        cout << val << ' ';  // print in sorted order

        if (elemIdx + 1 < arrays[arrIdx].size()) {
            minHeap.emplace(arrays[arrIdx][elemIdx + 1], arrIdx, elemIdx + 1);
        }
    }
}

int main() {
    int k, n;
    cin >> k >> n;

    // Input: k arrays each of size n
    vector<vector<int>> arrays(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arrays[i][j];
        }
    }

    mergeKsorted(arrays, k);
    return 0;
}
