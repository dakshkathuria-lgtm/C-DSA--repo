#include<iostream>
using namespace std;
const int N = 1e5;

int n , k;
int taste[N]{};
int calorie[N]{};
int dp[101][2*N+1]{};

// F(x,s): max taste by choosing some fruits from x to n-1 where contirbuitn of chosen fruits is s
// f(3,-5):dp[3][-5]: hum log -ve sum ko store nhi kar sakte
// so we will shift the array to store the -ve summ

int F(int x, int s){
    //stopping point
    if(x==n){
        if(s==0){
            return 0;
        } else{
            return -1e9;
        }
    }

    // s can be -ve so i wll store dp mei at index
    // dp[x][N+s]: // mai sum ko 10^5 se shift karke store karunag
    if(dp[x][N+s]!=-1){
        return dp[x][N+s];
    }

    // CURRENT STATE F(x,s)

    int op1 = taste[x] + F(x+1, s+(taste[x] - (k*calorie[x])));


    int op2 = 0 + F(x+1, s);

    int ans = max(op1, op2);
    return (dp[x][N+s]= ans);

}



int main(){
    cin >> n >> k;

    for(int i =0;i<n;i++){
        cin >> taste[i];
    }

    for(int i =0;i<n;i++){
        cin >> calorie[i];
    }

    int ans = F(0,0);
    if(ans < 0){
        cout << -1 << endl;
    }

    cout << ans << endl;
    return 0;
}