#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
const int N = 1e5;

int n , k;
int taste[N]{};
int calorie[N]{};
int dp[101][2*N+1]{};

// dp[i][s] = f(i-1, s);

int main(){
    cin >> n >> k;

    for(int i =0;i<n;i++){
        cin >> taste[i];
    }

    for(int i =0;i<n;i++){
        cin >> calorie[i];
    }

    //base condition
    // dp[0][shift+sum] = -1e9 or 0
    
    for(int s = 0;s<2*N+1;s++){
        dp[0][s] = -1e9;
    }

    // this is a valid path sum/contirbution is 0
    dp[0][N+0] = 0;

    // outer loop is for fruits
    for(int i =1;i<=n;i++){

        // current fruit ka contir pehel nikalo
        int contribution = taste[i-1] - k*(calorie[i-1]);

        // inner loop is for the fruits/contibution till the current fruit
        for(int s=0;s<(2*N);s++){
            // sum mei already shifted ke acc kar rhe

            //now for dp[i][s];

            int op1 = 0 + dp[i-1][s];

            // chossing the current
            int op2 = 0;
            int ns = s-contribution;
            if(ns>=0 and ns<2e5){
                op2 = taste[i-1] + dp[i-1][ns];
            }

            dp[i][s] = max(op1, op2);

        }
    }

    int ans = dp[n][N];

    if(ans<=0){
        cout << -1 << endl;
    } else{
        cout << ans << endl;
    }

    return 0;
}