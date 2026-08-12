#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
const int N = 1e5+2;

int n;
int height[N]{};
int dp[N]{};
int dp1[N]{};

// dp[x] = f(X) = minimum cost from xth stone till the last stone
int f(int x){
    if(x==1){
        return 0;
    }

    if(dp[x]!=-1){
        return dp[x];
    }

    int op1 = abs(height[x]-height[x-1]) + f(x-1);

    int op2 = INT_MAX; // as har stone se 2 kadam piche nhi jaa sakta
    if(x-2>=1){
        op2 = abs(height[x]-height[x-2])+ f(x-2);
    }

    int ans = min(op1, op2);
    return (dp[x]= ans);
}

int main(){
    cin >> n;
    for(int i =1;i<=n;i++){
        cin >> height[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << f(n) << endl;

    // ITERATIVE DP
    dp1[1] = 0;
    for(int i =2;i<=n;i++){
        int op1 = abs(height[i]-height[i-1]) + dp1[i-1];

        int op2 = INT_MAX;
        if(i-2>=1){
            op2 = abs(height[i]-height[i-2]) + dp1[i-2];
        }

        dp1[i] = min(op1, op2);
    }

    cout << dp1[n] << endl;
    
    return 0;
}