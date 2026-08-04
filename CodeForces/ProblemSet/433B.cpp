#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e5 + 3;
#define int long long

int n;
int a[N] , b[N];


int32_t main(){

    cin >> n;

    vector<int>pre1(n+1, 0);
    vector<int>pre2(n+1, 0);

    for(int i =1;i<=n;i++){
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b+1, b+n+1);

    for (int i = 1; i <= n; i++) {
        pre1[i] = pre1[i - 1] + a[i];
        pre2[i] = pre2[i - 1] + b[i];
    }

    int m, type, l, r;
    cin >> m;

    while(m--){
        cin >> type >> l >> r;
        if(type==1){
            cout << pre1[r] - pre1[l-1] << endl;
        } else{
            cout << pre2[r] - pre2[l-1] << endl;
        }
    }

    return 0;
}