#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
#define mod 1000000007
#define int long long
const int N = 1e5+4;

int k;
int dp[N]{};

int f(int x){
    if(x==0){return 1;}

    if(dp[x]!=-1){
        return dp[x];
    }

    int op1 = f(x-1)%mod; // last flowr is red
    int op2 = 0;

    if(x-k>=0){
        op2 = f(x-k)%mod;
    }

    return dp[x] = (op1%mod+ op2%mod)%mod;
}

int32_t main(){

    int t;
    cin >> t >> k;

    memset(dp, -1 , sizeof(dp));
    f(100001);

    // dp[i] : total ways to eat i flowers 

    // now cal the prefix of this dp array
    // pre[i] : total ways to eat flowers from 0 to ith flowers

    int pre[N]{};
    pre[0] = dp[0];
    for(int i =1;i<N;i++){
        pre[i] = pre[i-1] + dp[i];
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