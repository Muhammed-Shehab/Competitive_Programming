#include<iostream>
#include <vector>
using namespace std;

// Recursive function to check if a subset exists with sum = 0
// 'taken' ensures at least one element is chosen
void check(vector<int> &vec, int indx, int sum, int n, bool &present, bool taken) {
    // Base case: reached end of array
	if (indx == vec.size()) {
        // If sum = 0 and at least one element taken → subset exists
		if (sum == 0 && taken) {
			present = true;
			return;
		}
		return;
	}

    // Include current element in subset
	check(vec, indx + 1, sum + vec[indx], n, present, true);
    // Exclude current element from subset
	check(vec, indx + 1, sum, n, present, taken);
}

int main() {
	int t;
	cin >> t; // number of test cases
	while (t--) {
		int n;
		cin >> n; // size of array
		vector<int> vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec[i]; // input elements
		}
		bool present = false; // to store result
		check(vec, 0, 0, n, present, false);

        // Output result
		if (present) {
			cout << "Yes" << "\n";
		} else {
			cout << "No" << "\n";
        }
	}
	return 0;
}
