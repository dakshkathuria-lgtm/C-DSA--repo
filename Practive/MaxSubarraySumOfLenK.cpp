#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n , k;
    cin >> n >> k;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    int ans = INT_MIN;

    //APPROACH 1- BRUTE FORCE 
    for(int i =0;i<=n-k;i++){
        int sum = 0;
        for(int j = i;j<i+k;j++){
            sum+=a[j];
        }
        if(sum > ans) ans = sum;
    }

    cout << ans << endl;

    //APPROACH 2- SLIDING WINDOW

    int sp = 0, ep = 0, sum = 0;
    for(;ep<n;ep++){
        //expansion
        sum+=a[ep];
        

        //shriking
        if(ep>=k){
            sum-=a[sp];
            sp++;
        }


        //updation
        if(ep-sp+1==k){
            if(sum>ans) ans = sum;
        }
    }

    return 0;
}