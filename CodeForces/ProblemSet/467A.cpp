#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int cnt = 0;
    while(n--){
        int p, q;
        cin >> p >> q;
        if(p<q && p<=q-2){
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;   
}
