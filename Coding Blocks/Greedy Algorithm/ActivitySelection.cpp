#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct work {
    int stime;
    int etime;
    work(){}; 
    work (int s, int e){
        stime = s;         // start time
        etime = e;         // end time
    }
};

// greedy: sort activities by finishing time
bool comparator (work a, work b) {
    return a.etime < b.etime;
}

int main() {
    int t; cin >> t;       // number of test cases
    while (t--) {
        int n; cin >> n;   // number of activities
        vector<work> vec(n);
        for (int i = 0; i < n; i++) {
            int s,e; cin >> s >> e;
            vec[i] = work(s,e);   // input activity
        }

        sort(vec.begin(), vec.end(), comparator); // step 1: sort by end time

        int i = 1;          // iterator over activities
        int curr = 0;       // last chosen activity index
        int ans = 1;        // pick the first activity

        // step 2: select non-overlapping activities greedily
        while (i < n) {
            if (vec[curr].etime <= vec[i].stime) {
                curr = i;   // update last chosen
                ans++;      // activity count++
            }
            i++;            // move to next activity
        }

        cout << ans << endl;   // output result
    }
    return 0;
}
