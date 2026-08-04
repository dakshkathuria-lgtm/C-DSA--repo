#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i += 1) {
        cin >> a[i];
    }

    // Computations : n*n
    int suffix[n + 1]{};

    for (int i = n - 1; i >= 0; i -= 1) {
        int sum = 0;
        for (int j = n - 1; j >= i; j -= 1) {
            sum += a[j];
        }
        suffix[i] = sum;
    }

    //Computations n only
    int suffix[n+1]{};
    suffix[n-1] = a[n-1];
    for(int i =n-2;i>=0;i--){
        suffix[i] = suffix[i+1] + a[i];
    }
    for (int i = 0; i < n; i += 1) {
        cout << suffix[i] << " ";
    }
    return 0;
}