#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+3;
#define int long long

int n,m, type, l, r;
int a[N]{};
int b[N]{};

int f(int arr[], int x){
        
    if(x==r){
        return arr[x];
    }

    int ans = arr[x] + f(arr, x+1);
    return ans;

}

int32_t main(){

    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    cin >> m;

    while(m--){
        cin >> type >> l >> r;
        l--, r--;
        
        if(type==2){
            sort(b, b+n);
        }

        if(type==1){
            cout << f(a, l) << endl;
        } else{
            cout << f(b, l) << endl;
        }
    }



    return 0;
}