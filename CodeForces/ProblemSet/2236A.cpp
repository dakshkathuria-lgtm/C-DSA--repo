#include<iostream>
#include<climits>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        int a[n];
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
            cin >> a[i];
            if(a[i]>maxi) maxi = a[i];
            if(a[i]< mini) mini = a[i];
        }

        int k = maxi - mini +1;
        cout << k << endl;
    }
    return 0;   
}