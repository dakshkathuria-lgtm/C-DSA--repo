#include<iostream>
using namespace std;
int main(){
    int n , q;
    cin >> n >> q;
    long long a[n+1];
    for(int i =1;i<=n;i++){
        cin >> a[i];
    }

    long long pre[n+1]{};
    pre[1]=a[1];
    for(int i =2;i<=n;i++){
        pre[i] = pre[i-1] + a[i];
    }

    for(int i =1;i<=q;i++){
        int l , r;  
        cin >> l >> r;

        cout << pre[r]- pre[l-1] << endl;
    }
    return 0;
}