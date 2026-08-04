#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    //BUILD PREFIX ARRAY
    int pre[n+1]{};
    pre[0] = a[0];

    int maxi = 0, mini =0;

    for(int i =1;i<n;i++){
        pre[i] = pre[i-1] + a[i];   
    }

    for(int i =0;i<n;i++){
        if(pre[i]>maxi) maxi = pre[i];
        if(pre[i]<mini) mini = pre[i];
    }

    // FREQ ARRAY OF PREFIX ARRAY
    int freq[maxi-mini+1]{};
    for(int i =0;i<n;i++){
        int ce = pre[i];
        int us = ce - mini;
        freq[us]+=1;
    }

    freq[0-mini]+=1;


    int ans = 0;
    for(int i =0;i<maxi-mini+1;i++){
        if(freq[i] > 1){
            ans += (freq[i]*(freq[i]-1)/2);
        }
    }

    cout << ans << endl;
    return 0;
}