#include<iostream>
#include<algorithm>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        int a[n];
        for(int i =0;i<n;i++){
            cin >> a[i];
        }

        int sp=0 , ep = 0;
        int maxlen = 0;
        for(;ep<n;ep++){
            if(a[ep]==1){
                maxlen = max(maxlen, ep -sp);
                sp = ep+1;
            }
        }
        maxlen = max(maxlen, n-sp);

        cout << maxlen<< endl;
    }
    return 0;
}