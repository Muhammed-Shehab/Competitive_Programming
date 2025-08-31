#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> vec(n);
        for (int &x : vec) cin >> x;

        vector<int> lis(n, 1), lds(n, 1);

        // LIS (increasing subsequence ending at i)
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (vec[i] > vec[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        // LDS (decreasing subsequence starting at i)
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (vec[i] > vec[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        int ans = 0;
        // Maximum LIS + LDS - 1 at each pivot
        for (int i = 0; i < n; i++) {
            ans = max(ans, lis[i] + lds[i] - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}
