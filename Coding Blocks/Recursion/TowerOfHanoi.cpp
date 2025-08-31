#include <iostream>
using namespace std;

void call(int n, string src, string helper, string des) {
    if (n == 0) {
        return;
    }

    call(n-1, src, des, helper);

    cout << "Move " << n << "th disc from " << src << " to " << des << "\n";

    call(n-1, helper, src, des);

}

int main() {
    int n;
    cin >> n;
    call(n, "T1", "T3", "T2");
    cout << (2<<(n-1)) - 1;
}