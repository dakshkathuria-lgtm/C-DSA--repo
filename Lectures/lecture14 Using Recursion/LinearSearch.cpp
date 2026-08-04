#include<iostream>
using namespace std;
const int N=1e5 + 5;

int n;
int a[N];
int key;

bool F(int x){
    if(x==-1){
        return false;
    }

    if(a[x]==key){
        return true;
    }

    return F(x-1);
}

int main(){

    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    cin >> key;

    cout << F(n-1) << endl;

    return 0;
}