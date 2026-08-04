#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
char output[100];
int n;

void f(int x){
    if(x==2*n){
        output[x] = '\0';
        cout << output << endl;
        return ;
    }

    output[x] = '(';
    f(x+1);

    output[x] = ')';
    f(x+1);

    return ;
}

int main(){
    cin >> n;
    f(0);



    return 0;
}