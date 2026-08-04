#include<iostream>
using namespace std;


int n , h, l , r;
int a [2002];

// F(x, wt) : Max no of gud sleep from the xth sleep till n-1th sleep 
// where the current waking time is wt

int F(int x, int wt){
    // stopping point
    if(x==n){
        return 0;
    }

    int NSP01 = 0, NSP02 = 0; /* will tell me agar mai a[i] hour ke baad sleep karta hu toh 
                            good hai ki nhi..can only have values 0,1*/

    
    // next sleep ke liye waking time >> if current sleep wt+a[i] hr ke baad kari
    int NSWTop1 = (wt+a[x])%h;
    int NSWTop2 = (wt+a[x]-1)%h;


    if(NSWTop1 >= l and NSWTop1 <=r){
        NSP01 = 1; // current sleep good hai
    }

    if(NSWTop2 >= l and NSWTop2 <=r){
        NSP02 = 1; // current sleep good hai
    }

    // max number of good sleep agar aap current sleep a[i] hrs ke abad karte ho
    int op1 = NSP01 + F(x+1, NSWTop1);
    int op2 = NSP02 + F(x+1, NSWTop2);


    // current state ka ans F(x, wt)
    int ans = max(op1, op2);
    return ans;


}

int main(){
    cin >> n >> h >> l >> r;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    // starting point
    int ans = F(0,0);
    cout << ans << endl;


    return 0;
}