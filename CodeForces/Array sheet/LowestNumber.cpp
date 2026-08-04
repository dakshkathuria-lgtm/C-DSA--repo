#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int mini = INT_MAX;

    for(int i =1;i<=n;i++){
        cin >> a[i];
        if(a[i]<mini) mini = a[i];
    }

    for(int i =1;i<=n;i++){
        if(a[i]==mini){
            cout << mini << " " << i << endl;
            return 0;
        }
    }
}