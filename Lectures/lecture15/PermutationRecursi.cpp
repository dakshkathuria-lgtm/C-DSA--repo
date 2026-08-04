#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s;

void z(string s, int x){
    int n = s.length();
    if(x==n){
        return ;
    }
    swap(s[x], s[x+1]);
    z(s, x+1);
}

void f(string s , int x){
    int n = s.length();
    if(x==n){
        cout << s << endl;
        return ;
    }

    z(s, x);
    f(s, x+1);
}

int main(){

    cin >> s;

    f(s, 0);


    return 0;
}