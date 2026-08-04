#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
char output[100];
int n;

void f(int x, int ob, int cb){
    if(x==2*n){
        output[x] = '\0';
        cout << output << endl;
        return ;
    }

    if(cb<ob){
        output[x] = ')';
        f(x+1, ob, cb+1);
    }

    if(ob<n){
        output[x] = '(';
        f(x+1, ob+1, cb);
    }


    return ;
}

int main(){
    cin >> n;
    f(0, 0, 0);



    return 0;
}