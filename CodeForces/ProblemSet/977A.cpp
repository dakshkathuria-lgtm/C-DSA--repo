#include<iostream>

using namespace std;
// #define int long long

int main(){
    int n , k;
    cin >> n >> k;

    while (k--)
    {
        int ld = n%10;
        if(ld==0){
            n/=10;
        } else{
            n=n-1;
        }
    }

    cout << n << endl;
    
    return 0;
}