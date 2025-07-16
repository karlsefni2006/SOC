#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 4 == 1 || n % 4 == 2)
            cout << "second\n";
        else
            cout << "first\n";
    }
}
