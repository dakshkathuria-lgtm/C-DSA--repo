#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int dp[101][101]{};

    string getLCS(string &s, string &t, int lengthLCS){
        
        string ans = "";
        int n = s.length();
        int m = t.length();
        int i = n;
        int j = m;

        while(i>0 and j>0){
            if(s[i-1]==t[j-1]){
                ans.push_back(s[i-1]);
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            } else{
                j--;
            }
        }

        /// now have string lCS but ulta hai
        reverse(ans.begin(), ans.end());
        return ans;
    }

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
    int len = st.longestCommonSubsequence(s, t);

    cout << st.getLCS(s,t, len) << endl;
    return 0;
}