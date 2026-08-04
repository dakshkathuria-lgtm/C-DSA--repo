#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b>> c >> d;
        int cnt = 0;
        if(b>a){
            cnt+=1;
        }
        if(c>a){
            cnt+=1;
        } 
        if(d>a){
            cnt+=1;
        }
        cout << cnt << endl;
    }
    return 0;
}