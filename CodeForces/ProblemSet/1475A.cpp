#include<iostream>
using namespace std;


int main(){
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        //odd
        if(n % 2 != 0){
            cout << "YES" << endl;
            continue;
        }

        // evem
        int flag = 0;
        for(long long i =3;i*i<=n;i+=2){
            if(n%i==0){
                flag = 1;
                break;
            }
        }
        if(flag ==0) cout << "NO" << endl;
        else cout << "YES" << endl;

    }
    
    return 0;
}