#include<iostream>
#include<climits>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        int a[n];
        for(int i =1;i<=n;i++){
            cin >> a[i];
        }

        int mini = INT_MAX;
        for(int i =1;i<=n-1;i++){
            for(int j =i+1;j<=n;j++){
                int diff = a[i] + a[j] + j -i;
                if(diff < mini)  mini = diff;
            }
        }
        cout << mini << endl;
    }
    return 0;
}