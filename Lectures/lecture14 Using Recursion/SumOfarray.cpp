#include<iostream>
#include<climits>
#include<ctype.h>
const int N=1e5+5;

using namespace std;

int n;
int a[N];

int sum(int x ){
    if(x==0){
        return a[0];
    }

    int ans = a[x] + sum(x-1);
}

int main(){


    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    cout << sum(n-1) << endl;

    return 0;
}