#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Problem: Find the first negative number in every window of size k in a given array.

Approach:
- Use a sliding window of size k.
- Maintain a queue to keep track of negative numbers in the current window.
- For each window, the front of the queue is the first negative number.
- Pop the front from the queue if it goes out of the window.
- If no negative number is in the window, print 0.
Time Complexity: O(n) per test case
Space Complexity: O(k) for the queue
*/

int main() {	
	int t; 
	cin >> t; // number of test cases
	while (t--) {
		int n, k; 
		cin >> n >> k; // array size and window size
		vector<int> vec(n);
		for (int i = 0; i < n; i++) cin >> vec[i]; // input array

		queue<int> q; // queue to store negative numbers in current window
		int i = 0, j = 0; // window pointers

		while (j < n) {
			// If current element is negative, push to queue
			if (vec[j] < 0) q.push(vec[j]);

			// Expand window until size k
			if (j - i + 1 < k) j++;
			else if (j - i + 1 == k) { // window of size k
				if (!q.empty()) cout << q.front() << ' '; // first negative in window
				else cout << 0 << ' '; // no negative in window

				// Remove the element going out of the window from queue
				if (!q.empty() && q.front() == vec[i]) q.pop();

				i++; j++; // slide the window
			}
		}
		cout << endl;
	}
	return 0;
}
