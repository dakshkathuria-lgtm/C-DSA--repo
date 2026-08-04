#include<iostream>
#include<climits>
using namespace std;
const int N = 1e5 + 3;

int n;
int a[N]{};
int maxSum = INT_MIN;

int f(int x, int sum){
    if(x==n-2){

    }

    a[x] = -a[x];
    a[x+1] = -a[x+1];
    for(int i =0;i<n;i++){
        
    }
}


int main(){
    int t;
    cin>> t;
    while(t--){
        cin >> n;
        int add = 0;
        for(int i =0;i<n;i++){
            cin >> a[i];
            add+=a[i];
        }

        f(0, add);
    }
    return 0;
}