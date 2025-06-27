#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<long long> duration;
    vector<long long> deadline;
    for(int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        duration.push_back(a);
        deadline.push_back(b);
    }
    
    sort(duration.begin(),duration.end());
    long long reward=0,current_time=0,dead_sum=0;
    for(int i=0;i<n;i++){
        current_time+=duration[i];
        dead_sum+=deadline[i];
        reward+=current_time; 
    }
    cout<<(dead_sum-reward);
}
