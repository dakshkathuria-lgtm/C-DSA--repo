#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n];
   
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    int maxi = INT_MIN;
    int mini = INT_MAX;
    

    // BUILD PREFIX
    int pre [n+1]{};
    pre[0] = a[0];
    if(maxi<pre[0]) maxi= pre[0];
    if(pre[0]<mini) mini = pre[0]; 

    for(int i =1;i<n;i++){
        pre[i] = pre[i-1] + a[i];
        if(maxi<pre[i]) maxi = pre[i];
        if(pre[i]<mini) mini = pre[i]; 
    }
    for(int i =0;i<n;i++){
        cout << pre[i] << " ";
    }
    cout << endl;


   
    // BUILD FREQ OF PREFIX ARRAY
    int freq[maxi-mini+1]{};

    for(int i =0;i<n;i++){
        int ce=pre[i];
        int us = ce - mini;
        freq[us]+=1;
    }
    // instead of below condition 
    if(0-mini>=0)
        freq[0-mini]+=1;

    // if(freq[0]>0){
    //     cout << "Yes" << endl;
    //     return 0;
    // }

    for(int i =0;i<maxi-mini+1;i++){          // for 0 ki alag se i =1
        if(freq[i]>1 ){
            cout <<"Yes" << endl;
            return 0;
        }
        
    }
    cout << "No" << endl;
}