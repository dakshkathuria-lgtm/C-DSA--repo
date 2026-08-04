#include<iostream>
#include<cstring>
#include<climits>
#include"../HeaderFiles/HashMap.h"
using namespace std;

int32_t main(){

    HashTable<int> h;
    int n;
    cin >> n;
    for(int i =0;i<n;i++){
        string s;
        int x;
        cin >> s >> x;
        h.insert(s,x);
    }

    h.print();

    return 0;
}