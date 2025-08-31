#include<iostream>
#include <vector>
using namespace std;

// Recursive backtracking function to find all subsets with sum = k
void call(vector<int> &arr, int indx, int sum, int k, vector<int> &subs, vector<vector<int>> &vec) {
    
    // Base case: reached end of array
    if (indx == arr.size()) {
        if (sum == k) {
            vec.push_back(subs); // store valid subset
        }
        return;    
    }

    // Include current element
    subs.push_back(arr[indx]);
    call(arr, indx + 1, sum + arr[indx], k, subs, vec);

    // Backtrack: remove current element and explore excluding it
    subs.pop_back();
    call(arr, indx + 1, sum, k, subs, vec);
}

int main() {
    int n;
    cin >> n;
    vector<int> subs;                  // temporary subset
    vector<int> arr(n);                // input array
    vector<vector<int>> vec;           // store all valid subsets

    // input array elements
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;                          // target sum

    // call backtracking function
    call(arr, 0, 0, k, subs, vec);

    // print all subsets in reverse order
    for (int i = vec.size()-1; i >= 0; i--) {
        for (int j = vec[i].size() - 1; j >= 0; j--) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
