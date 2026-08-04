#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
using namespace std;

int n;

//F(x,y) : Minimum steps to reach n from x, y
//F(x,y) : 1 + min((x,x+y), (x+y, y))
// F(n,y) or F(x,n) = 0
// F(t,p) or F(p,t) where t or p are > n (INVALID WAY) return infinty

int F(int x, int y){
    // current path : F(x,y);
    // INVALID PATH KA ANS OEHLE LIKHO

    if(x> n or y> n){
        // return INT_MAX;     // int_max+1 minus hojayega rnage ke bahar
        return 1e8;
    } 

    // STOPPING POINT FOR VALID PATH
    if(x==n or y==n){
        return 0;
    }

    // Current state: F(x,y);
    int op1 = F(x+y, y);

    int op2 = F(x,x+y);

    // this ans will store the ans for the state F(x,y)
    int ans = 1 + min(op1, op2);


    return ans;
}

int main(){
    
    cin >> n;

    // recursion from the front
    // starting point
    cout << F(1, 1) << endl;

    return 0;
}