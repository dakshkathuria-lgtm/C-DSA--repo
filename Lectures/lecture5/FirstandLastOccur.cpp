#include<iostream>
using namespace std;

int main(){
    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int key;
    cin >> key;

    int fo=-1, lo=-1;
    for(int i =0;i<n;i++){
        if(a[i]==key){
            if(fo==-1){
                fo=i;
            }
            lo=i;
        }
    }

    cout << fo << " " << lo << endl;
    return 0;
}