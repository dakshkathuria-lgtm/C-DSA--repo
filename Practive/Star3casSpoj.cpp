#include<iostream>
#include<climits>
#include<ctype.h>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 21;

int n;
int a[N];
bool visited[N]{};


int f(int x){
    if(x==n){
        return 0;
    }

    int op1 = 1e8 , op2 = 1e8;

    visited[x]=1;

    if(x+1<=n and visited[x+1]==0){
        op1 = 1 + f(x+1);
    }

    if(x + a[x] <= n and visited[x+a[x]]==0 and x+a[x]>=0){
        op2 = 1 + f(x+a[x]);
    }

    visited[x]=0;

    int ans = min(op1, op2);
    return ans;
}


int main(){

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i =0;i<n;i++){
            cin >> a[i];
        }

        int ans = f(0);

        if(ans>1e7){
            cout << -1 << endl;
        } else{
            cout << ans << endl;
        }


        memset(visited, 0 , sizeof(visited));
    }




    return 0;
}