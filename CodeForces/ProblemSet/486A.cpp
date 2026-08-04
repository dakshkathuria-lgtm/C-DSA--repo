#include<iostream>
using namespace std;
#define int long long

int32_t main(){
    int n ;
    cin >> n;

    int SumEven = 0, sumOdd=0;
    if(n%2==0){
        cout << n/2 << endl;
        return 0;
    } else{
        cout << -n/2 - 1 << endl;
        return 0;
    }
    

    cout << SumEven-sumOdd << endl;
    return 0;
}