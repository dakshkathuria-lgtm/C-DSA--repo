#include<iostream>
#include<climits>
#include<cstring>
#include<iomanip>
using namespace std;
const int N = 1e5 +2;      

int dp[N]{};

// computations: no of unique staes * transition time
//n*1 ie n
int F(int x){
    if(x==1 || x==0){
        return x;
    }

    if(dp[x]!=-1){
        return dp[x];
    }

    int op1 = F(x-1);
    int op2 = F(x-2);

    int ans = op1 + op2;

    return (dp[x] = ans);
}

int main(){
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    int ans = F(n);
    cout << ans << endl;
    return 0;
}