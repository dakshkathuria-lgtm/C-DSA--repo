#include<iostream>
using namespace std;

long long fib(int x){
    if(x==1) return 0;
    if(x==2) return 1;
    long long a =0, b=1;
    for(int i =3;i<=x;i++){
        long long c = a+b;
        a = b;
        b = c;
    }
    return b;
}
int main(){
    int n;
    cin>>n;
    cout << fib(n);
    return 0;
}