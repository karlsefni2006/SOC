#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAX = 2e6 + 5; // Enough for n + m up to 2e6

vector<ll> fact(MAX), inv(MAX);

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

ll comb(ll a, ll b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * inv[b] % MOD * inv[a - b] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    ll n, m;
    cin >> n >> m;

    cout << comb(n + m - 1, m) << "\n";
}
