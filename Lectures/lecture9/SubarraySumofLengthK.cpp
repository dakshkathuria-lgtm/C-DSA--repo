#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int k ;
    cin >> k;

    int ans = INT_MIN;
    for(int i =0;i<=n-k;i++){
        int sum = 0;
        for(int j = i;j<i+k;j++){
            sum+=a[j];
        }
        if(ans<sum) ans= sum;
    }
    cout << ans << endl;
    return 0;
}