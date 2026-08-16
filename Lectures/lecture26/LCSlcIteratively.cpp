#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
using namespace std;

class Solution {
public:

    int dp[101][101]{};

    // dp[x][y] = f(x-1, y-1) : length of lcs from 0 to x-1

    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        dp[0][0] = 0;

        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        for(int j =0;j<=n;j++){
            dp[0][j] = 0;
        }

        for(int x=1;x<=n;x++){
            for(int y=1;y<=m;y++){
                if(s[x-1]==t[y-1]){
                    dp[x][y] = 1 + dp[x-1][y-1];
                } else{
                    int op1 = dp[x-1][y];
                    int op2 = dp[x][y-1];

                    dp[x][y] = max(op1, op2);
                }
            }
        }

        return dp[n][m];

        
    }
};

int main(){
    string s, t;
    cin >> s >> t;

    Solution st;
    cout << st.longestCommonSubsequence(s, t);
    return 0;
}