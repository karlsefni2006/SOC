#include<iostream>
#include<vector>
using namespace std;

int main(){  
    int n;cin>>n;
    vector<int> input(n,0);
    for(int i=0;i<n-1;i++){
        int temp;cin>>temp;
        input[temp-1]=temp;
    }
    int missing;
    for(int i=0;i<n;i++){
        if(!input[i]){
            missing=i+1;
            break;
        }
    }
    cout<<missing;

}