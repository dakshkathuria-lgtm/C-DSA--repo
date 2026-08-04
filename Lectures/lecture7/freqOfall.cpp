#include<iostream>
using namespace std;
int main(){

    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    // int target ;
    // cin >> target;
    // int cnt = 0;
    for(int i =0;i<n;i++){
        int cnt = 0;
        for(int j =0;j<n;j++){
            if(a[i]==a[j]){
                cnt++;
            }
        }
        cout << a[i] << "-->" << cnt << endl;
        
    }
    // cout << cnt << endl;
    return 0;
}