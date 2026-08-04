#include<iostream>
using namespace std;

int upper_bound(int a[], int n , int key){
    int s =0, e = n-1, ans = n;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(a[mid]>key){
            ans = mid;
            e = mid -1;
        } else{
            s = mid+1;
        }
    }
    return ans;
}

int lower_bound(int a[], int n , int key){
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
    return ans;
}

int main(){
    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    int key ;
    cin >> key;

    int ans1 = lower_bound(a, n, key);
    int ans2 = upper_bound(a, n, key);

    cout << ans2 - ans1 << endl;
    return 0;
}