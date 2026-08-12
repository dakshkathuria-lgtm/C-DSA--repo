#include<iostream>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int pre[101][101]{};

    int i =1;
    while(i<=m){
        int x, y;
        cin >> x >> y;
        x--, y--; // coordinaes are given 1 based i have taken 0 based

        pre[x][y]=1;

        i++;
    }

    // row ko resolve kiya
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(j==0){
                continue;
            }
            pre[i][j] = pre[i][j-1] + pre[i][j];
        }
    }

    // resolve the second dimension
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i==0){
                continue;
            }
            pre[i][j] = pre[i-1][j] + pre[i][j];
        }
    }

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }

    int ans = INT_MIN;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){

            // current division ke liye 4 opt
            int op1 = pre[i][j];
            int op2 = pre[n-1][j] - op1;
            int op3 = pre[i][n-1] - op1;
            int op4 = pre[n-1][n-1] - op1 - op2 - op3;

            int mini = min({op1, op2 , op3 ,op4});

            // across all the division maintina the max
            ans = max(mini, ans);
        }
    }

    cout << ans << endl;
    return 0;
}