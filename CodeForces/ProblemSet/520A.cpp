#include<iostream>
#include<climits>
#include<ctype.h>
#include<cstring>
using namespace std;

int main(){
    int n ;
    cin >> n;
    char ch[n];
    cin >> ch;

    for(int i =0;ch[i]!='\0';i++){
        ch[i] = tolower(ch[i]);
    }

    int freq[26]{};
    for(int i =0;i<n;i++){
        int ce = ch[i];
        freq[ce-'a']+=1;
    }

    for(int i =0;i<26;i++){
        if(freq[i]<1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}