#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> stack(n);
        for(int i=0;i<n;i++){
            cin>>stack[i];
        }
        int x=stack[0];
        for(int i=1;i<n;i++){
            x=x^stack[i];
        }
        if(x!=0)cout<<"first"<<endl;
        else cout<<"second"<<endl;
    }

}