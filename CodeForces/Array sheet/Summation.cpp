#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];

    long long sum = 0;
    for(int i =0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum>0){
        cout << sum << endl;
    } else{
        sum/=-1;
        cout << sum << endl;
    }
    return 0;
}