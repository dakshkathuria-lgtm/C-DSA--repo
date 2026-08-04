#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    // APPROACH 1- Direct printing 
    for(int i =n-1;i>=0;i--){
        cout << a[i] << " ";
    } 
    cout << endl;

    // APPROACH 2- Creating a new array
    int b[n];
    for(int i =0; i<n;i++){
        b[i] = a[n-1-i];
    }
    for(int i =0;i<n;i++){
        cout << b[i] << " ";
    }
    cout << endl;

    // APPROACH 3 - Using 2 pointers 
    int i =0, j=n-1;
    while(i<j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++, j--;
    }
    for(int i =0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}