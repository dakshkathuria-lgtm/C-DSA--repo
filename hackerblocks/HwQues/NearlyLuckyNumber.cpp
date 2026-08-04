#include<iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    int cnt{0};
    while(n>0){
        int ld{n %10};
        n = n/10;
        if((ld==7) || (ld==4)){
            cnt++;
        }
    }

    if((cnt==7) || (cnt==4)){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    
    return 0;
}