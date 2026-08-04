#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    
    //Sqaure of Array
    int b [n];
    for(int i =0;i<n;i++){
        b[i] = a[i] * a[i];
    }

    //Sorting of Sqaure of Array
    for(int i =0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
            if(b[i]>b[j]){
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    
    //Printing Sorted Arrat
    for(int i =0;i<n;i++){
        cout << b[i] << " ";
    }
    return 0;
    
}