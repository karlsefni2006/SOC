#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod(ll a, ll b, ll m) {
    if(a==0 && b==0)return 1;
    if(a==0 && b!=0)return 0;
    if (b == 0) return 1 % m;
    ll x = mod(a, b / 2, m);
    ll u = (x * x) % m;
    if (b % 2) return (u * a) % m;
    return u;
}

int main() {
    ll MOD = 1e9 + 7;
    int n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;

        ll x = mod(b, c, MOD - 1);  
        ll result = mod(a,x, MOD); 
        cout << result << '\n';
    }
}
