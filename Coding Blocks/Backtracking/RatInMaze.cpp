#include<iostream>
#include<vector>
using namespace std;

// Check if cell (i,j) is inside grid, not visited, and not blocked ('X')
bool isSafe(int i, int j, int n, vector<vector<bool>> &visited, vector<vector<char>> &vec, int m) {
	if(i < n && i >= 0 && j < m && j >= 0 && !visited[i][j] && vec[i][j] != 'X') {
		return true;
	}
	return false;
}

// Backtracking function to find a path from (i,j) to bottom-right
bool sol(vector<vector<char>> &vec, vector<vector<int>> &soln, int i, int j, vector<vector<bool>> &visited, int n, int m) {
    // Base case: reached destination
	if (i == n - 1 && j == m - 1) {
		soln[i][j] = 1;
		return true;
	}

	visited[i][j] = true;
	soln[i][j] = 1;

	// Explore all four directions: right, down, left, up
	if (isSafe(i, j + 1, n, visited, vec, m) && sol(vec, soln, i, j + 1, visited, n, m)) return true;
	if (isSafe(i + 1, j, n, visited, vec, m) && sol(vec, soln, i + 1, j, visited, n, m)) return true;
	if (isSafe(i, j - 1, n, visited, vec, m) && sol(vec, soln, i, j - 1, visited, n, m)) return true;
	if (isSafe(i - 1, j, n, visited, vec, m) && sol(vec, soln, i - 1, j, visited, n, m)) return true;

	// Backtrack: unmark current cell
	soln[i][j] = 0;
	visited[i][j] = false; 
	return false;
}

int main() {
	int n, m;
	cin >> n >> m; // grid dimensions

	vector<vector<char>> vec(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j]; // input grid ('X' = blocked)
		}
	}

	vector<vector<int>> soln(n, vector<int>(m));          // store path (1 = part of path)
	vector<vector<bool>> visited(n, vector<bool>(m, false)); // visited cells

	if (sol(vec, soln, 0, 0, visited, n, m)) {
		// print path matrix
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << soln[i][j] << " ";
			}
			cout << "\n";
		}
	} else {
		cout << "NO PATH FOUND";
	}
	return 0;
}
