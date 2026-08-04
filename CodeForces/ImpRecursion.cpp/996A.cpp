#include<iostream>
using namespace std;
#define int long long

int n;

int f(int x){
    if(x==0){
        return 0;
    }
    int money[] = {100, 20, 10, 5, 1};
    for(int y: money){
        if(x>=y){
            return x/y + f(x%y);
        }
    }
    return 0;
}

int32_t main(){
    cin >> n;
    
    cout << f(n) << endl;

    return 0;
}