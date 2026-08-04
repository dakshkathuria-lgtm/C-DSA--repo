#include<iostream>
#include<math.h>
using namespace std;
#define int long long


int32_t main(){

    int n;
    cin >> n;

    int newnum = 0;
    int exp = 1;
    while(n>=1){
        int x = n%10;
        n = n/10;
        if(n==0 && x==9){
            // do nothing
        } else{
            int y = 9 - x;
            if(x>y){
                x = y;
            }
        }
        newnum += x *exp;
        exp*=10;
    }

    cout << newnum << endl;


    return 0;
}