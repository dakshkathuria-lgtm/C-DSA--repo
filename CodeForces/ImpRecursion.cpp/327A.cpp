#include<iostream>
#include<algorithm>
using namespace std;
const int N = 102;

int n;
int a[N];

int f(int i , int j){

    if(i==n){
        return 0;
    }

    if(j==n ){
        j=i+1;
        return f(i+1, j);
    }

    int b[N];
    for (int k = 0; k < n; k++)
        b[k] = a[k];

    for(int k = i;k<=j;k++){
        b[k] =1- b[k];
    }

    int cnt_1=0;
    for(int l =0;l<n;l++){
        if(b[l]==1){
            cnt_1++;
        }
    }

    int ans = max(cnt_1, f(i, j+1));
  
    return ans;
}

int main(){
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    

    cout <<  f(0,0) << endl;


    return 0;
}