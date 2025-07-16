#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;


ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}


ll num(const vector<vector<int>>& factor, ll mod) {
    ll num = 1;
    for (auto& i : factor) {
        num = num * (i[1] + 1) % mod;
    }
    return num;
}


ll sum(const vector<vector<int>>& factor) {
    ll result = 1;
    for (auto& i : factor) {
        ll p = i[0], k = i[1];
        ll numerator = mod_pow(p, k + 1, MOD) - 1;
        if (numerator < 0) numerator += MOD;
        ll denominator = mod_pow(p - 1, MOD - 2, MOD);  
        ll term = numerator * denominator % MOD;
        result = result * term % MOD;
    }
    return result;
}


ll product(const vector<vector<int>>& factor) {
    ll total_divisors = 1;
    bool has_even_exponent = false;
    ll exponent_mod = MOD - 1;
    
    for (auto& i : factor) {
        total_divisors = total_divisors * (i[1] + 1) % (2 * exponent_mod);
        if ((i[1] + 1) % 2 == 0) {
            has_even_exponent = true;
        }
    }
    
    ll result = 1;
    
    for (auto& i : factor) {
        ll p = i[0], k = i[1];
        ll exponent = (k % (2 * exponent_mod)) * (total_divisors % (2 * exponent_mod)) % (2 * exponent_mod);
        exponent = exponent / 2;
        result = result * mod_pow(p, exponent, MOD) % MOD;
    }
    
    return result;
}



int main() {
    int n;
    cin >> n;
    vector<vector<int>> factor(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> factor[i][0] >> factor[i][1];
    }

    cout << num(factor, MOD) << " " << sum(factor) << " "<< product(factor) << "\n";

    return 0;
}
