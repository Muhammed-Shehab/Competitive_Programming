#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
   Problem: Intersection of Two Arrays with Frequency
   Approach: Hashmap (unordered_map) for frequency counting
   Time Complexity: O(n + m)   (n = size of a, m = size of b)
   Space Complexity: O(n)
*/

vector<int> intersect(vector<int>& a, vector<int>& b) {
    unordered_map<int,int> freq;         // store frequency of elements in a
    for (int val : a) 
        freq[val]++;

    vector<int> result;
    for (int val : b) {
        if (freq[val] > 0) {             // element present in both arrays
            result.push_back(val);
            freq[val]--;                 // reduce count
        }
    }
    return result;
}

int main() {
    int n; 
    cin >> n;                            // input size of arrays
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> result = intersect(a, b);
    sort(result.begin(), result.end());  // sort final intersection

    cout << '[';
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << ']';
    return 0;
}
