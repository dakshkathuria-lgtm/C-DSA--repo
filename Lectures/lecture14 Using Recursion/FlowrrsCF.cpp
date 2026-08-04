#include<iostream>
using namespace std;

// F(x) :: total ways to eat x flworrs
// f(x) : F(x-1) + F(x-k);
//F(0) : 1
int n, k;

int F(int x){
    if(x==0){
        return 1;
    }

    // total ways to eat x flowers when xth flower is red
    int op1 = F(x-1);

    // total ways to eat x flowers when xth flower is white
    int op2 = 0;
    if(x-k>=0){
        // now eat whigr flowers
        op2 = F(x-k);
    }

    int ans = op1 + op2;
    return ans;
}



int main(){
    cin >> n >> k;

    cout << F(n) << endl;;


    return 0;   
}