#include<iostream>
#include <vector>
using namespace std;

void change(string &s, string sNew,int indx, int x) {
	if (indx == s.size()) {
		for (int i = 1; i <= x; i++) {
			sNew += 'x';
		}
		cout << sNew ;
		return;
	}

	if ( s[indx] != 'x') change(s, sNew + s[indx], indx + 1, x);
	else change(s, sNew, indx + 1, x + 1);

}
int main() {
	string s;
	cin >> s;
	change(s, "", 0,0);
	return 0;
}