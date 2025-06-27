#include<bits/stdc++.h>
using namespace std;
bool sum(vector<vector<int>> a,int t,int& c,int& b){
        int n = a.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int sum=a[left][0]+a[right][0];
            if(sum==t){
                c=a[left][1]+1;
                b=a[right][1]+1;
                return true;
            }else if (sum<t)
            {
                left++;
            }
            else{
                right--;
            }    
        }
        return false;

    }
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    int target;cin>>target;
    vector<vector<int>> input;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        vector<int> y={x,i};
        input.push_back(y);
    }
    sort(input.begin(),input.end());
    bool found=false;
    int i=0;
    int a,b;
    for( ;i<n-1;i++){
        int t=target-input[i][0];
        vector<vector<int>> slice(input.begin() + i+1 , input.begin() + n);
        if(sum(slice,t,a,b)){
            found=true;
            break;
        }

    }
    if(found){
        cout<<input[i][1]+1<<" "<<a<<" "<<b;
    }
    else{
        cout<<"IMPOSSIBLE";
    }
}