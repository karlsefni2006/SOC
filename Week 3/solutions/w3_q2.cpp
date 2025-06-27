#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    long long low = 0;
    long long high = 1e18;
    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long products = 0;
        for (int i = 0; i < n; i++) {
            products += mid / times[i];
            if (products >= t) break; 
        }
        if (products >= t) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
}
