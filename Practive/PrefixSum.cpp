#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i += 1) {
        cin >> a[i];
    
    }

    // n*n computations 
    int pre[n+1]{};
    for(int i =0;i<n;i++){
        int sum = 0;
        for(int j =0;j<=i;j++){
            sum+=a[j];
        }
        pre[i] = sum;
    }

    for(int i =0;i<n;i++){
        cout << pre[i] << " ";
    }



    //OPTIMAL SOLUTION 
    pre[0]=a[0];
    for(int i =1;i<n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    for(int i =0;i<n;i++){
        cout << pre[i] << " ";
    }
    return 0;
}