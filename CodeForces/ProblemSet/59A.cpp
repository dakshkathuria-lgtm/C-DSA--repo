#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char ch[101];
    cin >> ch;

    int Uppercnt = 0 , lowerCnt = 0;

    for(int i =0;ch[i]!='\0';i++){
        if(ch[i]>=97 && ch[i]<=122){
            lowerCnt++;
        } else{
            Uppercnt++;
        }
    }   

    for(int i =0;ch[i]!='\0';i++){
        if(lowerCnt>Uppercnt){
            ch[i]=tolower(ch[i]);
        }else if(lowerCnt < Uppercnt){
            ch[i] = toupper(ch[i]);
        } else{
            ch[i]=tolower(ch[i]);
        }

    }

    cout << ch << endl;
    
    return 0;
}