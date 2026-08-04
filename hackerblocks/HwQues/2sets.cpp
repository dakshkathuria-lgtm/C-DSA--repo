#include<iostream>
using namespace std;

int main(){
    int n ;
    cin >> n;

    int totalSum = n*(n+1)/2;
    int target = totalSum/2;

    if(totalSum %2 != 0){
        cout << "No" << endl;
    } else{
        cout << "Yes" << endl;

        int cnt=0;

        int temp = target;
        for (int i = n; i >= 1; i--) {
            if (i <= temp) {
                cnt++;
                temp -= i;
            }
        }

        cout << cnt << endl;

        // PRINTING FIRST SET
        temp = target;
        for(int i =n;i>0;i--){
            if(i<=temp){
                cout << i << " ";
                temp-=i;
            }
        }
        cout << endl;

        cout << n - cnt << endl;

        // PRINTING SECOND SET
        temp = target;
        for(int i =n;i>0;i--){
            if(i<=temp){
                temp-=i;
            } else{
                cout << i << " ";
            }
        }
        cout << endl;

    }
    return 0;
}