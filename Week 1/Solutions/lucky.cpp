#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int lower;cin>>lower;
        int upper;cin>>upper;
        int lucky_no;
        int temp=0;
        vector<int> digits;
        for(int num=lower;num<=upper;num++){
            for(int j=num;j>0;j=j/10){
                digits.push_back(j%10);
            }
            int max=*max_element(digits.begin(),digits.end());
            int min=*min_element(digits.begin(),digits.end());
            int diff=max-min;
            if(diff>temp){
                temp=diff;
                lucky_no=num;
            }
            digits.clear();

        }
        cout<<lucky_no<<endl;
    }
}