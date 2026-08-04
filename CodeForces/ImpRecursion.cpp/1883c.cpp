#include<iostream>
using namespace std;
const int N = 1e5 + 3;

int t, n, k;
int a[N]{};

int pro(int a[]){
    int product = 1;
    for(int i=0;i<n;i++){
        product*=a[i];   
    }
    return product;
}

int f( int x){


    // if(pro(a)%k==0){
    //     return ans;
    // }

    if(x==n){
        return 1;
    }


    a[x] = a[x] + 1;

    if(pro(a)%k!=0){
        return 1 + f(x+1);
    }

    
}

int main(){
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for(int i =0;i<n;i++){
            cin >> a[i];
        }

        if(pro(a)%k==0){
            cout << '0' << endl;
            return 0;
        }

        cout <<  f(0) << endl;

    }
    




    return 0;
}