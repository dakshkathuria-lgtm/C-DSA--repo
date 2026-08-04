#include<iostream>
#include<cstring>
#include<ctype.h>
#include<climits>
using namespace std;

int main(){
    
    char s[101], g[101], t[101];
    cin >> s >> g >> t ; 

    int freq[256]{};

    for(int i =0;s[i]!='\0';i++){
        int ce = s[i];
        freq[ce]+=1;
    }
    for(int i =0;g[i]!='\0';i++){
        int ce = g[i];
        freq[ce]+=1;
    }for(int i =0;t[i]!='\0';i++){
        int ce = t[i];
        freq[ce]-=1;
    }
    

    for(int i =0;i<256;i++){
        if(freq[i]!=0){
            cout << "NO" << endl;
            return 0;
            
        }
    }
    cout << "YES" << endl;
    return 0;
}
