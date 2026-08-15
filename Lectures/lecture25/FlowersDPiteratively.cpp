#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
#define mod 1000000007
#define int long long
const int N = 1e5+4;

int32_t main(){
    int t, k;
    cin >> t >> k;

    int dp[100004]{};
    int pre[100004]{};

    // dp[i] = f[i] = dp[i-1] + dp[i-k]

    dp[0] = 1; // otoal ways to eat 0 flower
    pre[0] = dp[0];

    for(int i=1;i<100004;i++){
        dp[i] = dp[i-1] % mod;
        if(i-k>=0){
            dp[i]= (dp[i]%mod + dp[i-k]%mod)%mod ;
        }

        pre[i] = (pre[i-1] % mod + dp[i] % mod) % mod;
    }

    int i=1;
    while(i<=t){
        int a, b;
        cin >> a >> b;

        cout << pre[b] - pre[a-1] << endl;

        i++;
    }
    return 0;
}
