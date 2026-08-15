#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
#define int long long
#define mod 1000000007
const int N = 1e5 + 3;
int a[N]{};

// F(n, k) : total ways to distribute k candies among n children
int dp[101][N]{};


int f(int n, int k){

    // stopping point
    if(k<0){
        // total ways to distribute less than 0 candies among some children
        return 0;
    }

    if(n==1){
        if(k<=a[1]){
            return 1;
        } else{
            return 0;
        }
    }

    if(dp[n][k]!=-1){
        return dp[n][k];
    }

    // int MaximumCandyCurrentChildCanHave = min(a[n], k);
    // int ans = 0; // total ways to distribute k candies among n child i.e the answer for the current state f(n,k)

    // for(int i =0 ; i<= MaximumCandyCurrentChildCanHave;i++){
    //     ans = (ans % mod + f(n-1, k-i)% mod )% mod;
    // }

    int ans = 0; 
    int part1 = 0;
    if(k>0){
        part1 = f(n, k-1)%mod;
    }
    int part2 = f(n-1, k) % mod;

    int part3 = 0;
    if(k-a[n]-1>=0){
        part3 = f(n-1, k-a[n]-1)%mod;
    }

    ans = (part1 % mod + part2 % mod - part3 % mod + mod) % mod;
    return dp[n][k] = ans;
}

int32_t main(){
    int n, k;
    cin >> n >> k;

    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    // starting point: recursion from the back
    cout << f(n, k) << endl;

    return 0;
}
