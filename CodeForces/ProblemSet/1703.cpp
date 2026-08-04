#include<iostream>
#include<ctype.h>
#include<cstring>
using namespace std;

char s[4];
char check[]{"YES"};

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        for(int i =0;s[i]!='\0';i++){
            s[i] = toupper(s[i]);
        }

        if(strcmp(s, check)==0){
            cout << "YES" <<  endl;
        } else{
            cout << "NO" << endl;
        }

    }
    return 0;
}