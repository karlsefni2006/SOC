    #include<bits/stdc++.h>
    using namespace std;


    bool sum(vector<vector<int>> &a,int t,int& c,int& b){
        int n = a.size();
        int left=0;
        int right=n-1;
        sort(a.begin(),a.end());
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
        int n;cin>>n;
        int target;cin>>target;
        int a=0,b=0;
        vector<vector<int>> input;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            vector<int> v={x,i};
            input.push_back(v);
        }
    if(sum(input,target,a,b)){
        cout<<a<<" "<<b;
    }
    else{
        cout<<"IMPOSSIBLE";
    }
    }