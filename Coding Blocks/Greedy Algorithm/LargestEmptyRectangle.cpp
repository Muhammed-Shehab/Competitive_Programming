#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; 
	cin >> n;

	vector<int> hor(n), ver(n);
	for (int i = 0; i < n; i++) {
		cin >> hor[i] >> ver[i];
	}

	// Sort coordinates separately
	sort(hor.begin(), hor.end());
	sort(ver.begin(), ver.end());

	int maxH = 0, maxV = 0;

	// Find maximum horizontal and vertical gaps between consecutive points
	for (int i = 1; i < n; i++) {
		maxV = max(maxV, (ver[i] - ver[i - 1]) - 1);
		maxH = max(maxH, (hor[i] - hor[i - 1]) - 1);
	}

	// Largest empty rectangle area between towers
	cout << maxV * maxH;
	return 0;
}
