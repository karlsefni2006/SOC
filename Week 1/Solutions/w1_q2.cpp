#include <iostream>
#include <string>
using namespace std;

int main(){
    string seq;cin>>seq;
    int count=1;
    int max=1;
    for(int i=0; i< seq.length();i++){
        if(seq[i] == seq[i+1]){
            count++;
        }
        else{
            if(max < count){
                max=count;
            }
            count = 1;
        }
    }
    cout << max;
}
