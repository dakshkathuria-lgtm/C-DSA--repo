#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+5;

int n;
int a[N];

void F(int x){
    //stoppping point
    if(x==n-1){
        return;
    }

    int flag = 0;
    for(int j = 0;j<n-1;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
            flag = 1;
        }
    }

    if(flag==0){
        // no swap
        return ;
    }

    return F(x+1);
}


int main(){
    cin >>n;
    for(int i =0;i<n;i++){
        cin >>a[i];
    }

    F(0);

    for(int i =0;i<n;i++){
        cout << a[i];
    }

    return 0;
}