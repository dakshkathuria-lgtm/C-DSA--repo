#include<iostream>
using namespace std;
const int N = 1e5+3;
#define int long long

int t, n;
int a[N]{} , b[N]{};


int f(int x, int scoreop){
    if(x==n){
        return scoreop;
    }


    int scoreOp1 = scoreop-a[x];
    int op1 = f(x+1,scoreOp1);

    int scoreOp2 = b[x] - scoreop;
    int op2 = f(x+1, scoreOp2);

    return max(op1, op2);

}

int32_t main(){

    cin >> t;
    while(t--){
        cin >> n;
        for(int i =0;i<n;i++){
            cin >> a[i];
        }
        for(int i =0;i<n;i++){
            cin >> b[i];
        }

        cout << f(0, 0) << endl;
    }

    return 0;
}