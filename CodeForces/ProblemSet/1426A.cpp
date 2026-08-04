#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;

        if(n==1 || n==2){
            cout << 1 << endl;
            continue;
        }

        int rem = n-2;

        int floor = ceil(rem+x-1)/x + 1;

        cout << floor << endl;
    }


    return 0;
}