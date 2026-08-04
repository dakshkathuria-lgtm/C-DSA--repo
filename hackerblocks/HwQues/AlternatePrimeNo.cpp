#include<iostream>
using namespace std;

int main(){
    int n ;
    cin >> n;
    int c= 1;
    int ct{0};
    while(c<=n){
        bool isPrime = true;

        if(c==1){
            c++;
            continue;
        }

        if(c==2){
            cout << c << endl;
            ct++;
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
            ct++;
            if(ct%2!=0){
                cout << c << endl;
            }
        }
        c++;
    }

    return 0;
}

