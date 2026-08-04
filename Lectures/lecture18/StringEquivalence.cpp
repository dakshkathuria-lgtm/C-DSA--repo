#include<iostream>
#include<climits>
#include<ctype.h>
using namespace std;
int n;

char output[12];

void f(int x, char mx){
    if(x==n){
        output[x]=='\0';
        cout << output << endl;
        return ;
    }

    for(char ch ='a';ch<=mx;ch++){
        output[x] = ch;

        if(ch==mx){
            f(x+1, mx+1);
        } else{
            f(x+1, mx);
        }
    }
}


int main(){
    cin >> n;

    f(0, 'a');

    return 0;
}