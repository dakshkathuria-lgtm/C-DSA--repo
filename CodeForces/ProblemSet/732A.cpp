#include<iostream>
using namespace std;
int main(){
    int k , r;
    cin >> k >> r;
    int pro = 1;
    int minBuy = 1;

    while(((k*pro) - r) %10 != 0 ){
        if((k*pro)%10==0){
            break;
        }
        
        pro++;
        minBuy = pro;
        
    }
    cout << minBuy << endl;
    return 0;
}