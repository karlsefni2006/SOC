#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD=1e9+7;
const int MAX=1e6+2;

vector<ll> fact(MAX),inv(MAX);

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void precompute(){
    fact[0]=1;
    for(int i=1;i<MAX;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    inv[0]=1;
    inv[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1) % MOD;
}

}


ll comb(ll a , ll b){
    
    if (b < 0 || b > a) return 0;
    ll res = fact[a];
    res = res * inv[b] % MOD;
    res = res * inv[a - b] % MOD;
    return res;
}





int main(){
    int n;
    cin>>n;
    vector<ll> vals(2);
    precompute();
    while(n--){
        cin>>vals[0]>>vals[1];
        cout<<comb(vals[0],vals[1])<<"\n";
    }
}

