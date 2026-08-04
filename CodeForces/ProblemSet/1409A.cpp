#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        // long long minMoves = 0;
        if(a==b){
            cout << "0" << endl;
        } else if(a<b){
            long long diff = b-a;
            if(diff%10==0){
                long long x = ceil(diff/10);
                cout << x << endl;
            } else{
                long long x = ceil((diff/10)+1);
                cout << x << endl;
            }
        } else{
            long long diff = a-b;
            if(diff%10==0){
                long long x = ceil(diff/10);
                cout << x << endl;
            } else{
                long long x = ceil((diff/10)+1);
                cout << x << endl;
            }
        }

    }
    return 0;
}