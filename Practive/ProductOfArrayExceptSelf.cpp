#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i += 1) {
        cin >> a[i];
    }

    int pre[n+1]{};
    pre[0] = 1;
    for(int i =1;i<n;i++){
        pre[i] = pre[i-1] * a[i-1];
    }

    int suf[n+1]{};
    suf[n-1]=1;
    for(int i =n-2;i>=0;i++){
        suf[i] = suf[i+1] * a[i+1];
    }

    for (int i = 0; i < n; i++) {
        cout << pre[i] * suf[i] << " ";
    }
    return 0;
}