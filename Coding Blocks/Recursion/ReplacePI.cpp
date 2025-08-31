#include<iostream>
using namespace std;

// Recursive function to replace all occurrences of "pi" with "3.14"
void replace(string &s, int ind = 0) {
    // Base case: reached end of string
	if (s.size() == ind) {
		cout << s << "\n"; // print modified string
		return;
	}

    // If current and next char form "pi", replace it
	if (s[ind] == 'p' && s[ind + 1] == 'i') {
		s.replace(ind, 2, "3.14");     // replace "pi" with "3.14"
		replace(s, ind + 4);           // move index past "3.14"
	} else {
		replace(s, ind + 1);           // move to next character
	} 
}

int main() {
	int t;
	cin >> t;  // number of test cases
	while (t--) {
		string s;
		cin >> s;   // input string
		replace(s); // start recursion
	}
	return 0;
}
