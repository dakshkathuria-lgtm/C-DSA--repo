#include<iostream>
using namespace std;

int main(){
    int n ;
    cin >> n;
    int c= 1;
    while(c<=n){
        bool isPrime = true;

        if(c==1){
            c++;
            continue;
        }

        if(c==2){
            cout << c << endl;
            c++;
            continue;
        }

        for(int i =2;i<c;i++){
            if(c%i==0){
                isPrime = false;
                break;
            }
        }

        if(isPrime){
            cout << c << endl;
        }
        c++;
    }

    return 0;
}

