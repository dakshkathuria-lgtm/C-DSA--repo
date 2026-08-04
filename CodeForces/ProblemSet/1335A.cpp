#include<iostream>
#include<cstring>
#include<climits>
#include<ctype.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        if(n==1 || n==2){
            cout << "0" << endl;
            continue;
        }

    
        
        if(n%2!=0)
            cout << n/2 << endl;
        else{
            cout << n/2 -1 << endl;
        }

    }
    return 0;
}