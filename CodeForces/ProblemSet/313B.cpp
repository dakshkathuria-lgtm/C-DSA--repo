#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();

    vector<int> pre(n,0);

    pre[0] = 0;
    for(int i =0;i<n-1;i++){
        pre[i+1] = pre[i] + (s[i]==s[i+1]? 1 : 0);
    }

    int m, l, r;
    cin >> m;
    
    while (m--)
    {
        cin >> l >> r;
        l--; // convert to 0 indexing
        

        cout << pre[r-1] - pre[l] << endl;
    }
    
    

    return 0;
}