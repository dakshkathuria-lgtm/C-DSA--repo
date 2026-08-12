#include<iostream>
#include<climits>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
const int N = 1e5+2;

int n;
int a[N]{}, b[N]{}, c[N]{};
int dp[N][3]{};

// dp[day][activity] = f(n,t) is mx happines from 1st day till nth day where 
// activity performed on nth day is t   


int main(){
    cin >> n;
    for(int i =1;i<=n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    memset(dp, -1, sizeof(dp));

    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];

    for(int i =2;i<=n;i++){
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }

    // now i have entire ans for every state


    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;

    return 0;
}   