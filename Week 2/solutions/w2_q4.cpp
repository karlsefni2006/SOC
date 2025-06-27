#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    vector<int> input;
    while(cin>>x){
        input.push_back(x);
    }
    deque<int> window;
    for(int i=0;i<input[input.size()-1];i++){
        window.push_back(input[i]);
    }
    cout<<"["<<*max_element(window.begin(),window.end());
    int left=1;
    int right=input[input.size()-1];
    for (;right<input.size()-1;left++,right++){
        window.pop_front();
        window.push_back(input[right]);
        cout<<","<<*max_element(window.begin(),window.end());
    }
    cout<<"]";
}