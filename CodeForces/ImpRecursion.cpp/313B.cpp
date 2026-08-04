#include<iostream>
#include<string>
#include<cstring>
#include<climits>

using namespace std;

string s;
int m, l , r;

int f(int x){
    int n = s.length();
    if(x==r){
        return 0;;
    }

    if(s[x-1]==s[x]){
        return 1 + f(x+1);
    }
    return f(x+1);
}

int main(){

    cin >> s;
    cin >> m;
    while(m--){
        cin >> l >> r;
        cout <<  f(l) << endl;
    }

    return 0;
}
