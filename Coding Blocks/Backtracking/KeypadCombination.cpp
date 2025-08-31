#include<iostream>
#include <vector>
using namespace std;

// Mapping digits 1-9 to letters as on a phone keypad
vector<string> keypad =  {"abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};

// Recursive function to generate all combinations
void print(string &s, int indx, string ne, int &count) {
    // Base case: all digits processed
	if (indx == s.size()) {
		cout << ne << " "; // print current combination
		count++;           // increment total count
		return;            // return to previous recursion level
	}

	int digit = s[indx] - '1'; // map char digit to index 0-8

    // Try all letters corresponding to current digit
	for (char ch : keypad[digit]) {
		print(s, indx + 1, ne + ch, count); // append letter and recurse
	}
}

int main() {
	string s;
	cin >> s;          // input string of digits
	int count = 0;     // count total combinations

	print(s, 0, "", count); // start recursion

	cout << "\n" << count;  // print total combinations
	return 0;
}
