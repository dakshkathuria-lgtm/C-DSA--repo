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

    int maxi = INT_MIN;
    
    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j =i;j<n;j++){
            sum +=a[j];
            if(sum>maxi) maxi = sum;
            for(int k =i;k<=j;k++){
                cout << a[k] << " ";
            }
            cout << "=" << sum << endl;
        }
        cout << endl;
    }
    cout << "-------------"<< endl;
    cout << maxi << endl;
    return 0;
}