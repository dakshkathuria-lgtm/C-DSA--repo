#include<climits>
#include<iostream>
#include<cstring>
using namespace std;
char input[100]{};
char output[100]{};
int cnt = 0;

void f(int x, int y){
    if(input[x]=='\0'){
        // now i have 1 path and it is stored in output
        output[y] = '\0'; // casue char arryas always end with null characetrs
        cout << output << endl;
        cnt ++;
        return ;
    }

    // f(x,y);

    //op1 choose to be part of subsequence
    output[y] = input[x];
    f(x+1, y+1);

    // op2 do not choose to be a part
    f(x+1, y);

    // now i have the ans for the current state which is 
    return ;
}



int main(){

    cin >> input;

    f(0,0);

    cout << cnt << endl;

    return 0;
}