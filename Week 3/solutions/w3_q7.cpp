#include<bits/stdc++.h>
using namespace std;

int main(){
    int l,n;
    cin>>l>>n;
    priority_queue<long long, vector<long long>, greater<long long>> stick;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        stick.push(x);
    }
    long long sum=0;
    while(stick.size()>1){
        long long x=stick.top();
        stick.pop();
        long long y=stick.top();
        stick.pop();
        sum+=(x+y);
        stick.push(x+y);
    }
    cout<<sum;

}