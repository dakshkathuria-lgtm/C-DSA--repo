#include<iostream>
#include<climits>
#include<ctype.h>
#include<cmath>

using namespace std;

#define int long long

// bool isSquare(int x){
//     int root = sqrt(x);
//     return root*root == x;
// }


int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        for(int i =0;i<n;i++){
            cin >> a[i];
            sum+=a[i];
        }

        // APPROACH 1 - 
        // if(isSquare(sum)) cout << "YES" << endl;
        // else cout << "NO" << endl;


        // APPROACH 2- BINARY SEARCH
        bool found = false;
        int s =0, e=1e9;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(mid*mid==sum){
                found = true;
                break;
            } else if(mid*mid>sum){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }

        if(found) cout << "YES" << endl;
        else cout << "NO" << endl;


    }
    return 0;
}