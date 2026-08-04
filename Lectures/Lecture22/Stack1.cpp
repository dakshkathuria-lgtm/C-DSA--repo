#include<iostream>
#include<climits>
#include<cstring>
#include"../HeaderFiles/Stack.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    Stack<int> st;
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        st.push(x);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}