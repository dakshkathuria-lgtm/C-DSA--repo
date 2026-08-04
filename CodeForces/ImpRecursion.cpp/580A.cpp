
#include<iostream>
using namespace std;
const int N = 1e5 +3;

int n;
int a[N]{};
int best = 1;

int f(int x, int curLen){
    if(x==n-1){
        best = max(best, curLen);
        return best;
    }

    int ans;
    if(a[x+1]>=a[x]){
        return f(x+1, curLen+1);
    } else{
        best = max(best, curLen);
        return f(x+1, 1);
    }

}

int main(){
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    if(n==1){
        cout << 1 << endl;
    }else{
        cout << f(0,1) << endl;
    }
    return 0;
}
