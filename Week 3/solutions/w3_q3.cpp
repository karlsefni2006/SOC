#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

long long dice(int n,vector<bool> &status,vector<long long> &memo){
    if(status[n-1]){
        return memo[n-1];
    }
    else{
        if(n<7){
            memo[n-1]=pow(2,n-1);
            status[n-1]=true;
            return memo[n-1];
        }
        else{
            memo[n-1]=(dice(n-1,status,memo)+dice(n-2,status,memo)+dice(n-3,status,memo)+dice(n-4,status,memo)+dice(n-5,status,memo)+dice(n-6,status,memo))%mod;
            status[n-1]=true;
            return memo[n-1];
        }
    }

}

int main(){
    int n;cin>>n;
    vector<bool> status(n,false);
    vector<long long>  memo(n);
    cout<<dice(n,status,memo);

}