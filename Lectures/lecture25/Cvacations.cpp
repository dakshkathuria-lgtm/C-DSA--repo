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

int f(int n, int activity){
    if(n==0){
        return 0; // invalid day
    }

    if(dp[n][activity]!=-1){
        return dp[n][activity];
    }

    int op1 = 0, op2 = 0, op3 = 0;

    if(activity==0){
        // nth day acitivty is A
        op1 = a[n] + max(f(n-1, 1), f(n-1, 2));
    }

    if(activity==1){
        // nth day acitivty is B
        op1 = b[n] + max(f(n-1, 0), f(n-1, 2));
    }

    if(activity==2){
        // nth day acitivty is C
        op1 = c[n] + max(f(n-1, 0), f(n-1, 1));
    }

    return (dp[n][activity] = max({op1, op2 , op3}));
}

int main(){
    cin >> n;
    for(int i =1;i<=n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    memset(dp, -1, sizeof(dp));

    int op1 = f(n, 0); // activty A
    int op2 = f(n, 1); // acttivity B
    int op3 = f(n, 2); // activity C

    cout << max({op1, op2, op3}) << endl;

    return 0;
}   