#include<bits/stdc++.h>

using namespace std;

double round_half_even(double x) {
    double scaled = x * 1e6;
    double intpart;
    double frac = modf(scaled, &intpart); // intpart is floor(scaled), frac is decimal part

    if (fabs(frac - 0.5) < 1e-8) {
        // It's exactly halfway
        if (fmod(intpart, 2.0) == 0.0) {
            return intpart / 1e6; // already even
        } else {
            return (intpart + 1.0) / 1e6; // round up to even
        }
    } else {
        // Not a tie: just round normally
        return round(scaled) / 1e6;
    }
}

int main(){
    int n;cin>>n;
    vector<int> r(n);
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    double expected =0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int ri=r[i];int rj=r[j];
            int count=0;
            for(int x=1;x<ri+1;x++){
                count+=min(rj,x-1);
            }
            double prob=(double)count/(ri*rj);  
            expected+=prob;    
        }
    }
    cout<<fixed<<setprecision(6)<<round_half_even(expected)<<"\n";

}
