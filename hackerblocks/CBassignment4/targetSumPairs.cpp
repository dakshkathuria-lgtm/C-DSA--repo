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
    int i =0,j=n-1;
    while(i<j){
        int sum = a[i] + a[j];
        if(sum ==target){
            cout << a[i] << " " << "and " << a[j] << endl; 
            i++, j--;
        } else if(sum<target){
            i++;
        } else{
            j--;
        }
    }
    return 0;
}