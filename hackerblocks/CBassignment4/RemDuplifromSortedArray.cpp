#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int maxi = 0, mini = 0;
    for(int i =0;i<n;i++){
        cin >> a[i];
        if(maxi<a[i]) maxi = a[i];
        if(mini > a[i]) mini = a[i];
    }

    //BUILD FREQ ARRAY
    int freq[maxi-mini+1]{};
    for(int i =0;i<n;i++){
        int ce = a[i];
        int us = ce - mini;
        freq[us]+=1;
    } 

    //STORE LENGTH 
    int cnt = 0;
    for(int i =0;i<maxi-mini+1;i++){
        if(freq[i]>=1){
            cnt ++;
        }
    }

    //OUTPUT 
    cout << cnt << endl;
    for(int i =0;i<maxi-mini+1;i++){
        if(freq[i]>=1){
            int os = i+mini;
            cout << os << " ";
        }
    }
    return 0;
}