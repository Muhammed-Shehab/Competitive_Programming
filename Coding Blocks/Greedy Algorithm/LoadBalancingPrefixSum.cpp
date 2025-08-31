#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
	int n; cin >> n;
	vector<int> vec(n);

	// Build prefix sum while reading input
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		if (i != 0) vec[i] += vec[i - 1];
	}

	int total = vec[n-1];         // Total sum of array
	int avg = total / n;          // Expected average per part

	// If total sum not divisible by n, balancing is impossible
	if (total % n != 0) {
		cout << -1;
		return 0;
	}

	int left, ans = 0;
	// For each partition, compute imbalance and track maximum
	for (int i = 0; i < n; i++) {
		left = abs(((i + 1) * avg) - vec[i]);
		ans = max(ans, left);
	}

	cout << ans;
	return 0;
}
