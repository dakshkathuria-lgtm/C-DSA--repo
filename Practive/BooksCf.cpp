#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n , t;
    cin >> n >> t;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    int ans = INT_MIN;

    // APPROACH 1 - BRUTE FORCE
    for(int i =0;i<n-1;i++){
        int tc = 0, count = 0;
        for(int j =i;j<n;j++){
            tc+=a[j];
            if(tc>t){
                break;
            }
            count++;
        }
        if(count > ans) ans = count;
    }
    cout << ans << endl;


    // APPROACH 2- SLIDING WINDOW
    int sp = 0 , ep =0, cnt = 0, tc = 0;
    for(;ep<n;ep++){
        // EXPANSION
        tc +=a[ep];

        // SHRINKING
        while(tc>t && sp<=ep){
            tc-=a[sp];
            sp++;
        }

        // UPDATION
        if(ep-sp+1>ans)
            ans = ep - sp +1;
    }

    cout << ans << endl;
    return 0;
}
