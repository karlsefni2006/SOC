#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(ll n){
    vector<ll> digits;
    while(n > 0 ){
        digits.push_back(n % 10);
        n = n / 10;
    }
    reverse(digits.begin(), digits.end());

    ll length = digits.size();
    if(length == 1){
        return false;
    }
    else if(digits[0] != 1){
        return false;
    }
    for(ll i=1; i<length-1; i++){
        if(digits[i] == 0){
            return false;
        }
    }
    if(digits[length-1] == 9){
        return false;
    } 

    return true;
}




int main(){
    int t;cin>>t;

    while(t--){
        ll n;cin>>n;
        if(f(n))cout<<"YES\n";
        else cout<<"NO\n";

    }
}