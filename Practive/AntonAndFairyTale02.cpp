#include<iostream>
#include<climits>
#include<ctype.h>
#include<cstring>

using namespace std;

#define int long long

int32_t main(){

    int n, m;
    cin >> n >> m;

    if(n<=m){
        cout << m << endl;
        return 0;
    }

    //APPROACH 1- LINEAR SEARCH

    // ans is m+k, we need to find the first value of k that satisfies this eq
    int s =1, e=2e9, ans = 0;
    for(int k =1;k<=e;k++){
        if ((k * (k + 1)) / 2 >= (n - m)) {
            ans = k;
            break;
        }
    }

    // APPROAACH 2 - BINARY SEARCH
    int ans01 = 0;
    while(s<=e){
        int mid = (s + e) / 2;

        if ((mid * (mid + 1)/2) >= n - m) {
            ans01 = mid;
            e = mid - 1;
        } else {

            s = mid + 1;
        }
    }

    cout << m+ans << endl;
    cout << m + ans01 << endl;
    return 0;
}