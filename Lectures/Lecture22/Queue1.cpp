#include<bits/stdc++.h>
#include"../HeaderFiles/Queue.h"
using namespace std;

int main(){
    Queue<int> q;
    int n ;
    cin >> n;
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        q.Push(x);
    }

    while(!q.empty()){
        cout << q.front1() << " ";
        q.pop();
    }
    return 0;
}