#include<iostream>
using namespace std;

// Check if placing 'num' at position (r, c) is valid
bool isSafe(int sd[9][9], int num, int r, int c) {
    // Check row and column
	for (int i = 0; i < 9; i++) {
		if (sd[r][i] == num || sd[i][c] == num) {
			return false;
		}
	}

    // Check 3x3 subgrid
	int gr = (r / 3) * 3;
	int gc = (c / 3) * 3;
	for (int i = gr; i < gr + 3; i++) {
		for (int j = gc; j < gc + 3; j++) {
			if (num == sd[i][j]) {
				return false;
			}
		}
	}

	return true;
}

// Find the next empty cell in the sudoku grid
bool empty(int &r, int &c, int sd[9][9]) {
	for (r = 0; r < 9; r++) {
		for (c = 0; c < 9; c++) {
			if (sd[r][c] == 0) {
				return true; // empty cell found
			}
		}
	}
	return false; // no empty cell
}

// Backtracking solver
bool solve(int sd[9][9]) {
	int r, c;

    // If no empty cell, sudoku solved
	if (!empty(r, c, sd)) {
		return true;
	}

    // Try numbers 1 to 9
	for (int num = 1; num <= 9; num++)  {
		if (isSafe(sd, num, r, c)) {
			sd[r][c] = num;       // place number
			if (solve(sd)) return true; // recurse
			sd[r][c] = 0;         // backtrack
		}
	}

	return false; // trigger backtracking
}

int main() {
	int sudoku[9][9];

    // Input sudoku grid (0 = empty)
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
		}
	}

	solve(sudoku); // solve sudoku

    // Print solved sudoku
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
