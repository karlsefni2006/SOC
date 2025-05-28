#include<iostream>

using namespace std;

int main(){
    int n;cin>>n;
    for (int i=0;i<n;i++){
        int n,k;
        cin>>n>>k;
        bool poss=false;
        for(int j=1;n-2*j>=0;j++){
            if ((n-2*j)%k==0){
                poss=true;
                break;
            }
        }
        cout<<(poss? "YES":"NO")<<endl;

    }
}
