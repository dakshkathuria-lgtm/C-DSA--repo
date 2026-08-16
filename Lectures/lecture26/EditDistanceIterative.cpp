#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:

    int dp[501][501]{};

    // f(x,y) : min no of operations to convert s from [x-1 to 0] and t from [y-1 to 0]

    int minDistance(string s, string t) {

        int n= s.length();
        int m= t.length();
        
        for(int i =0;i<=n;i++){
            for(int j =0;j<=m;j++){
                if(i==0){
                    dp[i][j] = j;
                } else if(j==0){
                    dp[i][j] = i;
                } else if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else{
                    int op1 = dp[i-1][j];
                    int op2 = dp[i][j-1];
                    int op3 = dp[i-1][j-1];

                    dp[i][j] = 1 + min({op1, op2, op3});
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
    cout << st.minDistance(s, t) << endl;

    return 0;
}