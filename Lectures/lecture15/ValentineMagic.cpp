#include<iostream>
#include<cstring>
#include<ctype.h>
#include<algorithm>
using namespace std;

int n, m;
int a [5001], b[5001];

//f(x,y) : min cost by choosing some boys from xth idx till n-1th idx and choosing 
// some girls from yth idx till n-1th idx

int f(int x , int y){

    if(x==n){
        return 0;
    }
    if(y==m){
        return 1e8;
    }

    int op1 = abs(a[x]-b[y]) + f(x+1, y+1);

    // does not chosoes
    int op2 = 0 + f(x,y+1);

    int ans = min (op1, op2);
    return ans;
}


int main(){
    cin >> n >> m;

    for(int i = 0 ;i < n ;i++){
        cin >> a[i];
    }

    for(int i =0;i<m;i++){
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b,b+m);

    cout << f(0,0) << endl;
    return 0;
}