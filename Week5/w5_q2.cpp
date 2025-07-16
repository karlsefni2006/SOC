#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        unordered_map<ll,ll> dp;
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            unordered_map<ll,ll> next_dp;

            for (auto &[c, count] : dp) {
                ll c1 = c + a[i];
                ll c2 = abs(c + a[i]);

                next_dp[c1] = (next_dp[c1] + count) % MOD;
                next_dp[c2] = (next_dp[c2] + count) % MOD;
            }

            dp = move(next_dp); 
        }

        long long max_c = LLONG_MIN;
        for (auto &[c, count] : dp) {
            max_c = max(max_c, c);
        }

        cout << dp[max_c] << '\n';
    }
}
