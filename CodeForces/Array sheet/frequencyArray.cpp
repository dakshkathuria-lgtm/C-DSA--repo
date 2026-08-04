#include<iostream>
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    int freq[m+1]{};
    for(int i =0;i<n;i++){
        int ce = a[i];
        freq[ce]+=1;
    }

    for(int i =1;i<m+1;i++){
        cout << freq[i] << endl;
    }
    return 0;
}