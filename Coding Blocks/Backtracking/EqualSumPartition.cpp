#include<iostream>
#include <vector> 
using namespace std;

// Recursive function to explore all ways to partition array into two groups with equal sum
void print(vector<int>& arr, int indx, int sum1, int sum2, vector<int> &grp1, vector<int> &grp2, int &count) {
    // Base case: all elements are considered
	if (indx == arr.size()) {
        // If sums are equal, print groups and increment count
		if (sum1 == sum2) {
			count++;
			for (int n : grp1) {
				cout << n << " ";
			}
			cout << "and";
			for (int n : grp2) {
				cout << " " << n;
			}
			cout << "\n";
		}
		return;
	}

    // Include current element in first group
	grp1.push_back(arr[indx]);
	print(arr, indx + 1, sum1 + arr[indx], sum2, grp1, grp2, count);
	grp1.pop_back(); // backtrack

    // Include current element in second group
	grp2.push_back(arr[indx]);
	print(arr, indx + 1, sum1, sum2 + arr[indx], grp1, grp2, count);
	grp2.pop_back(); // backtrack
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];  // input array
	}

	vector<int> grp1;     // first group
	vector<int> grp2;     // second group
	int count = 0;        // number of valid partitions

    // start recursive partitioning
	print(arr, 0, 0, 0, grp1, grp2, count);

	cout << count;  // total number of valid partitions

	return 0;
}
