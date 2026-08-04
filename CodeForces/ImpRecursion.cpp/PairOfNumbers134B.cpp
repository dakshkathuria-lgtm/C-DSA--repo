#include<iostream>
#include<climits>
using namespace std;

int n ;

int f(int a, int b){

    if(a==1 and b==1 ){
        return 0;
    }

    int op1=0, op2 = 0;
    if(a-b>0){
        op1 = 1 + f(a-b, b);
        return op1;
    }

    if(b-a>0){
        op2 = 1+f(a,b-a);
        return op2;
    }

    return INT_MAX/2;
}

int Solve(){
    int final = INT_MAX;
    for(int i =1;i<=n/2;i++){
        int ans = f(i, n);
        final = min(ans , final);
    }
    return final;
}

int main(){
    cin >> n;

    if(n==1){                
        cout << 0 << endl;
        return 0;
    }

    int val = Solve();  
    cout << val << endl;

    return 0;
}