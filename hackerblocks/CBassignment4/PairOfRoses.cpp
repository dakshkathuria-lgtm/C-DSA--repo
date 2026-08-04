#include<iostream>
#include<climits>
using namespace std;

int main(){

    int t;
    cin >> t;
    for(int i =0;i<t;i++){
        int n ;
        cin >> n;
        int a[n];
        for(int i =0;i<n;i++){
            cin >> a[i];
        }
        int moneyavail;
        cin >> moneyavail;

        cout << endl;

        int mini = INT_MAX;

        for(int i =0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                if(a[i]+a[j]==moneyavail){
                    int diff;
                    if(a[j]>a[i]) diff = a[j] - a[i];
                    else diff = a[i] - a[j];
                    if(diff<mini){
                        mini = diff;
                    }
                    cout << "Deepak should buy roses whose prices are "<<a[i]<<" and "<<a[j];
                }
            }
        }
    }

    return 0;
}