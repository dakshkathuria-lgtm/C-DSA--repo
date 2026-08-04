#include<iostream>
using namespace std;
int main(){
    char ch[100];
    cin >> ch;
    int freq[256]{};
    for(int i =0;ch[i]!='\0';i++){
        int ce = ch[i];
        freq[ce]+=1;
    }
    for(int i =0;i<256;i++){
        if(freq[i]>0){
            cout << (char)i << " " << freq[i] << endl;
        }
    }
    return 0;
}