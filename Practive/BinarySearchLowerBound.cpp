#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    int key ;
    cin >> key;

    int s =0, e = n-1, ans = n;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(a[mid]>=key){
            ans = mid;
            e = mid -1;
        } else{
            s = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}