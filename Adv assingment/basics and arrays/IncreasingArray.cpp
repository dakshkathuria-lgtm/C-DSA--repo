#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    
    for(int i =0;i<n;i++){
        cin>>a[i];
    }

    long long moves = 0;
    for(int i =0;i<n-1;i++){
        if(a[i+1]>a[i]){
            continue;
        } else{
            moves+=a[i] - a[i+1];
            a[i+1] = a[i];
        }
    }

    cout << moves;

    return 0;
}