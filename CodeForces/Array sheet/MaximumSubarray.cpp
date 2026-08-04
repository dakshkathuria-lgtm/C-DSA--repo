#include<iostream>
#include<climits>
using namespace std;
int main(){
    int t ;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];

        for(int i =0;i<n;i++){
            cin >> a[i];
        }

        // int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            int maxi = INT_MIN;
            for(int j =i;j<n;j++){
                maxi = max(maxi, a[j]);
                cout << maxi << " ";
            }
        }
    }
    return 0;
}