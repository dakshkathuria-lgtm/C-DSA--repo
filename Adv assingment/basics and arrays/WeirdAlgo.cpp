#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    if(n==1)
        return 0;
    cout << n << " ";
    while(n!=1){
        if(n%2==0){
            n=n/2;
            cout << n << " ";
        } else{
            n=3*n + 1;
            cout << n << " ";
        }
    }
}