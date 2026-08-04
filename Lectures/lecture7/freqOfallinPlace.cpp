#include<iostream>
#include<climits>
using namespace std;
int main(){

    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    
    for(int i =0;i<n;i++){
        if(a[i]==INT_MAX) continue;
        int key = a[i];
        int cnt = 0;
        for(int j =i;j<n;j++){
            if(a[j]==key){
                cnt++;
                a[j]=INT_MAX;
            }
        }
        cout << key << "-->" << cnt << endl;

    }
    // cout << cnt << endl;
    return 0;
}