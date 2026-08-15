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

            int ans = 0; 
            int part1 = 0;
            if(j>0){
                part1 = dp[i][j-1]%mod;
            }
            int part2 = dp[i-1][j] % mod;

            int part3 = 0;
            if(j-a[i]-1>=0){
                part3 = dp[i-1][j-a[i]-1]%mod;
            }

            ans = (part1 % mod + part2 % mod - part3 % mod + mod) % mod;
            
            dp[i][j] = ans;
        }
    }

    // starting point: recursion from the back
    cout << dp[n][k] << endl;

    return 0;
}
