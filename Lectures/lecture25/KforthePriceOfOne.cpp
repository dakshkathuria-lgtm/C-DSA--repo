#include<iostream>
#include<climits>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, p, k;
        cin >> n >> p >> k;

        int a[n+1]{};
        for(int i =1;i<=n;i++){
            cin >> a[i];
        }

        sort(a, a+n);

        int dp[n+1]{};
        // dp[i]: min cost to buy till the ith item

        for(int i =1;i<=n;i++){
            if(i<k){
                dp[i] = dp[i-1] + a[i];
            } else if(i==k){
                dp[i] = a[i];
            } else{
                dp[i] = dp[i-k] + a[i];
            }
        }

        // now i have the entire dp/prefix array
        // iterate over this dp array and find out the max t-shirt u can buy in p price

        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dp[i]<=p){
                // can buy all the t shirts till the ith item
                ans = i;
            }
        }

        cout << ans << endl;
    }
    return 0;
}