#include<iostream>
using namespace std;

int t, n;

void f(int x){

    if(x==0){
        cout << "YES" << endl;
        return ;
    }

    if(x<2020){
        cout << "NO" << endl;
        return;
    }

    if(x%2020==0){
        f(x-2020);
    } else{
        f(x-2021);
    }
}

int main(){

    cin >> t;
    while(t--){
        cin >> n;
        if(n<2020){
            cout << "NO" << endl;
            continue;
        }

        f(n);
    }

    return 0;
}