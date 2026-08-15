#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
#define int long long
#define mod 1000000007
const int N = 1e5 + 3;
int a[N]{};

// dp[n][k]  : total ways to distribute k candies among n children
int dp[101][N]{};

int32_t main(){
    int n, k;
    cin >> n >> k;

    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }

    // base condtion
    // in interative dp we have to fill each and evry box even boxes where jaana is not possible
    for(int j =0;j<=k;j++){ // j represents candies
        if(j<=a[1]){
            dp[1][j] = 1;
        } else{
            dp[1][j] = 0;
        }
    }

    
    for(int i =2;i<=n;i++){
        for(int j = 0;j<=k;j++){

            // dp[i][j] storing ans for f(i,j)
            // max candy the ith child can have is minimum of a[i], j
            int Maxi = min(a[i], j);
            int ans = 0; // store the ans for the current state
            for(int z =0 ;z<= Maxi;z++){
                ans = (ans % mod + dp[i-1][j-z]% mod )% mod;
            }

            // current state ka ans 
            dp[i][j] = ans;
        }
    }

    // starting point: recursion from the back
    cout << dp[n][k] << endl;

    return 0;
}
