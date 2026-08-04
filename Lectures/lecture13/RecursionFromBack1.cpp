#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

/*
F(x) : multiply a from x to b;

F(x) : a*F(x-1);
F(1) = a;
F(0) = 1;

Stopping point:
F(b) : a/F(b+1) = 1

*/

int a,b;

int F(int x){
    // current state : F(x);
    //Stopping Point
    if(x==1){
        return 1;
    }

    //current state F(x)
    //task and next state
    int ans = a*F(x-1);

    return ans;

}


int main(){

    
    cin >> a >> b;

    //Starting point
    int ans = F(b);
    cout << ans << endl;
    
    return 0;
}