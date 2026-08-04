#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n];
    int maxi= INT_MIN;
    for(int i =0;i<n;i++){
        cin >> a[i];
        if(a[i]>maxi)   maxi = a[i];
    }

    int freq[maxi+1]{};
    // ITERATE OVER ORIGINAL ARRAY AAND BUIL FREQ ARRAY
    return 0;
}