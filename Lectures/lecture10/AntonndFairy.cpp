#include<iostream>
#define int long long
using namespace std;

int32_t main(){
    int n , m;
    cin >> n >> m;

    if(n<m){
        cout << n << endl;
        return 0;
    }


    int day = 1;
    int BG = n;
    while(BG>0){
        BG-=day;

        if(BG<=0){
            break;
        }

        day+=1;
        BG+=m;
        if(BG>n){
            BG+n;
        }
    }
    return 0;
}