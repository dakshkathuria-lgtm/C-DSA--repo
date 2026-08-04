#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n];
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int maxIdx, minIdx = 0;
    for(int i =0;i<n;i++){
        cin >> a[i];
        if(a[i]>maxi){
            maxi = a[i];
            maxIdx = i;
        }
        if(a[i]<mini){
            mini = a[i];
            minIdx = i;
        }
    }

    int temp = a[maxIdx];
    a[maxIdx] = a[minIdx];
    a[minIdx] = temp;
    

    for(int i =0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}