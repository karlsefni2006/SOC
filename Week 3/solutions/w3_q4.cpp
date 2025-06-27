#include<bits/stdc++.h>
using namespace std;

int f(int i , int j ,string &s1,string &s2,vector<vector <int>> &dp){
    if(i<0){return j+1;}
    if(j<0){return i+1;}
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j])return dp[i][j]=f(i-1,j-1,s1,s2,dp);
    return dp[i][j]=1+min(f(i-1,j,s1,s2,dp),
                    min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
}

int main(){
    string s1 , s2;
    cin>>s1>>s2;
    int i=s1.size()-1;
    int j=s2.size()-1;
    vector<vector <int>> dp(i+1,vector<int>(j+1,-1));
    cout<<f(i,j,s1,s2,dp);
}