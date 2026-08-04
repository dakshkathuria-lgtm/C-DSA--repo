#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

/*
F(x) : multiply a from x to b;

F(x) : a*F(x+1);

Stopping point:
F(b) : a/F(b+1) = 1

*/

int a,b;

int F(int x){
    // current state : F(x,a,b);
    //Stopping Point
    if(x==b){
        return a;
    }

    //current state F(x)
    //task and next state
    int ans = a*F(x+1);

    return ans;

}


int main(){

    
    cin >> a >> b;

    //Starting point
    cout << F(1) << endl;
    
    return 0;
}