#include<iostream>
#include<climits>
#include<cstring>
#define int long long 
using namespace std;
int32_t main(){
    int n , m;
    cin >> n >> m;

    if(m>=n){
        cout << n << endl;
        return 0;
    }

    int day = 1;
    int bg = n;
    while(bg>0){
        bg-=day;

        if(bg<=0){
            break;
        }

        day++;
        bg+=m;

        if(bg>n){
            bg = n;
        }
    }

    cout << day << endl;

    return 0;
}