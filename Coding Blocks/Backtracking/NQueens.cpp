#include<iostream>
#include<vector>
using namespace std;

// Check if a queen can be safely placed at (x, y)
bool isSafe(int n, int x, int y, vector<vector<bool>> &prsnt) {
    // Check bounds
	if (!(x < n && y < n && x >= 0 && y >= 0)) return false;

    // Check column above
	for (int i = 0; i < x; i++) {
		if (prsnt[i][y]) return false;
	}

    // Check upper-left diagonal
	for (int i = x, j = y; j >= 0 && i >= 0; i--, j--) {
		if (prsnt[i][j]) return false;
	}

    // Check upper-right diagonal
	for (int i = x, j = y; j < n && i >= 0; i--, j++) {
		if (prsnt[i][j]) return false;
	}

	return true;
}

// Recursive function to place queens row by row
void print(int n, int i, int j, vector<vector<bool>> &prsnt, int &c) {
    // Base case: all queens placed
	if (i == n) {
		c++; // increment solution count
        // Print current configuration
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				if(prsnt[r][c]) {
					cout << "{" << r + 1 << "-" << c + 1 << "} ";
				}
			}
		}
		return;
	}

    // Try placing queen in current row
	for (int k = j; k < n; k++) {
		if(isSafe(n, i, k, prsnt)) {
			prsnt[i][k] = true;          // place queen
			print(n, i + 1, 0, prsnt, c); // recurse to next row
			prsnt[i][k] = false;         // backtrack
		}
	}
}

int main() {
	int n;
	cin >> n; // input size of board
	int c = 0; // count of solutions
	vector<vector<bool>> prsnt(n, vector<bool>(n)); // board

	print(n, 0, 0, prsnt, c); // start backtracking
	cout << "\n" << c;        // print total solutions
	return 0;
}
