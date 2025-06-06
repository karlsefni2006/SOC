#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    sort(input.begin(),input.end());
    long long middle = input[n/2];
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(input[i]-middle);
    }
    cout<<sum;

}