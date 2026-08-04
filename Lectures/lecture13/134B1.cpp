#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
using namespace std;

int n;

int F(int x, int y){
    if(x==1 and y ==1){
        return 0;
    }

    // current state : F(x,y):
    int op1 = 0, op2=0;
    if(x-y>0){
        op1 = 1 + F(x-y, y);
        return op1;
    }

    if(y-x>0){
        op2 = 1+F(x,y-x);
        return op2;
    }
}



int Solve(){
    int final = INT_MAX; // minimum steps cross all the parts
    for(int i =1;i<n/2;i++){
        // current pair: i, n-i
        // cal minimum steps from this pair to i,n-i to 1,1
        // and across all find minimum

        int ans = F(i,n-i); // store minimum steps from current pair to 1,1
        final = min(ans, final);    
    }
}

int main(){
    
    cin >> n;
    int val = Solve(); // for pair generation jaha se 1,1 tak ka time ham nikalenge

    // recursion from the front
    // starting point
    cout << val << endl;

    return 0;
}