#include<iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i] ;
    }
    int target;
    cin >> target;
    //SORTING 
    for(int i=0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    } 
    //TRIPLET
    for(int i =0;i<n-2;i++){
        for(int j =i+1;j<n-1;j++){
            for(int k = j+1;k<n;k++){
                if(a[i]+a[j]+a[k]==target){
                    cout << a[i] << " "<< a[j] << " "<< a[k] << endl;
                }
            }
        }
    }   
    return 0;
}