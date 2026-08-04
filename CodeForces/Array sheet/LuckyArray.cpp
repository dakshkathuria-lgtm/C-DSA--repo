#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];

    int mini = INT_MAX;

    for(int i =0;i<n;i++){
        cin >> a[i];
        if(mini > a[i]) mini = a[i];
    }

    int cnt = 0;
    for(int i= 0;i<n;i++){
        if(a[i]==mini) cnt++;
    }

    if(cnt%2!=0) cout << "Lucky" << endl;
    else cout << "Unlucky" << endl;

    return 0;
}