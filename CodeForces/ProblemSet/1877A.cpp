#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        for(int i =0;i<n-1;i++){
            cin >> a[i];
            sum += a[i];
        }

        int reqNum = 0-sum;
        // if(sum<0){
        //     reqNum = 0 - sum;
        // } else{
        //     reqNum = 0 - sum;
        // }

        cout << reqNum << endl;
    }


    return 0;
}