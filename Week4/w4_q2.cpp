#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD =1e9+7;

//l is left pointer -1

ll sum(ll l,ll r){
 // very imp , we are not allowinng the modulus(the remainder) to become negative and be careful for modular overflow , so best o give mod for everything
    const ll inv2 = 500000004;
    ll a = (r % MOD) * ((r + 1) % MOD) % MOD * inv2 % MOD;
    ll b = (l % MOD) * ((l + 1) % MOD) % MOD * inv2 % MOD;
    return (a - b + MOD) % MOD;
}



ll div(ll n){
    ll l=1,r=1;
    ll sigma=0;
    while(n/l>0){
        ll d=n/l;
        r=n/d+1;
        sigma=(sigma+(sum(l-1,r-1)*d)%MOD)%MOD;
        l=r;
    }
    return sigma;

}

int main(){
    ll n;cin>>n;
    cout<<div(n);
}