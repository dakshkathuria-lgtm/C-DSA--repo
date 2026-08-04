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

    int sp = 0, ep = 0;
    int sum =0;

    int ans = INT_MIN;
    for(;ep<n;ep++){
        //Explansion
        sum += a[ep];

        //SHRINKING
        if(ep>=k){
            sum-=a[sp];
            sp++;
        }

        //Updation
        if(ep-sp+1==k){
            if(ans<sum) ans= sum;
        }
    }
    cout << ans << endl;
    return 0;
}