#include<iostream>
#include<climits>
#include<ctype.h>
#include<algorithm>
using namespace std;

int n , a , b, c;

int f(int x){
    if(x==0){
        return 0;
    }

    if(x<0){
        return -1e9;
    }

    int op1 = 1+f(x-a);
    int op2 = 1+f(x-b);
    int op3 = 1+f(x-c);

    int ans = max({op1, op2, op3});
    return ans;
}

int main(){

    cin >> n >> a >> b >> c;

    int ans = f(n);
    cout << ans << endl;

    return 0;
}