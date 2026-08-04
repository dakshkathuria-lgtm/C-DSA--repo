#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool lucky = true;
    int temp = n;
    while(temp>0){
        int ld = temp%10;
        temp = temp/10;
        if(ld == 7 || ld == 4){
            continue;
        } else{
            lucky = false;
            break;
        }
    }

    if(lucky){
        cout << "YES" << endl;
    } else{
        if(n%4==0 || n%7==0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}