#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find the two unique numbers in an array where every other number appears twice.
Approach: XOR trick
-----------------------------------
Example:
Input:
6
4 2 3 2 3 5

Output:
4 5
*/

pair<int, int> findUniqueNumbers(const vector<int> &arr) {
    int XOR = 0;

    // Step 1: XOR all numbers → gives XOR = num1 ^ num2
    for (int num : arr) XOR ^= num;

    // Step 2: Find rightmost set bit (to separate num1 and num2)
    int rightmostBit = XOR & -XOR;

    // Step 3: Divide numbers into two groups & XOR separately
    int num1 = 0, num2 = 0;
    for (int num : arr) {
        if (num & rightmostBit) num1 ^= num;
        else num2 ^= num;
    }

    return {min(num1, num2), max(num1, num2)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    auto [a, b] = findUniqueNumbers(arr);
    cout << a << " " << b << "\n";

    return 0;
}
