#include<iostream>
using namespace std;
int main(){

    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int visited[n]{};
    for(int i =0;i<n;i++){
        if(visited[i]==1) continue;
        int cnt = 1;
        for(int j =i+1;j<n;j++){
            if(a[i]==a[j]){
                cnt++;
                visited[j] = 1;
            }
        }
        cout << a[i] << "-->" << cnt << endl;
        cout << cnt << endl;
    }
    // cout << cnt << endl;
    return 0;
}