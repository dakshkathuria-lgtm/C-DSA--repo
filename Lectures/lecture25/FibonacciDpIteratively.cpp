#include<iostream>
#include<climits>
#include<cstring>
#include<iomanip>
using namespace std;
const int N = 1e5 +2;      

int dp[N]{};

int F(int n){
    dp[0] = 0;
    dp[1] = 1;

    for(int i =2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    // maine nth state ka ans nikal liya and store dp[n] mei kara
    return dp[n];
}

int main(){
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    int ans = F(n);
    cout << ans << endl;
    return 0;
}