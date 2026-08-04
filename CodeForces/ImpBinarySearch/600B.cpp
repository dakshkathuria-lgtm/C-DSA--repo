#include<iostream>
#include<ctype.h>
#include<climits>
#include<string>
#include<algorithm>

using namespace std;

int upper_bound(int a[], int n, int x){
    int s = 0, e = n-1;
    int ans = n;
    while(s<=e){
        int mid = s = (e-s)/2;
        if(a[mid]>x){
            ans=mid;
            e = mid-1;
        } else{
            s = mid+1;
        }
    }
    return ans;
}

int main(){
    int n , m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    for(int i =0;i<m;i++){
        cin >> b[i];
    }

    // APPROACH 1 
    for(int i =0;i<m;i++){
        int key = b[i];
        int cnt =0;
        for(int i =0;i<n;i++){
            if(a[i]<=key){
                cnt++;
            }
        }   
        cout << cnt << " ";
    }

    // APPROACH 2 OPTIMISED
    sort(a, a+n); //nlogn
    for(int i =0;i<m;i++){
        int ce =b[i];
        int ans = upper_bound(a, n, ce);
        cout << ans << " ";
    }
    return 0;
}