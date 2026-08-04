#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
int main(){
    char ch[101];
    cin >> ch;

    // for(int i=1;ch[i]!='\0';i++){

    //     if(((ch[0] >=65 and ch[0]<=90) and (ch[i]>=65 and ch[i]<=90))){
    //         ch[0] = tolower(ch[0]);
    //         ch[i] = tolower(ch[i]);
    //         // cout << ch << endl;

    //     } else if(((ch[0]>=97 and ch[0]<=122) and (ch[i]>=65 and ch[i]<=90))){
    //         ch[0] = toupper(ch[0]);
    //         ch[i] = tolower(ch[i]);
    //         // cout << ch << endl;

    //     } else{
    //         // cout << ch << endl;
    //     }
    // }
    cout << ch << endl;
    return 0;
}