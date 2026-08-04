#include<iostream>
#include<climits>
#include<ctype.h>
#include<cstring>
using namespace std;



int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n , k;

        cin >> n >> k;

        char ch[n+1];
        cin >> ch;


        if(n-k<2){
            cout << "NO" << endl;
            continue;
        }

        bool found = false;
        for(int i =1;i<=n-k;i++){
            if(ch[i]=='0'){
                ch[i]='1';
            } else{
                ch[i]='0';
            }

            if(ch[i+2]=='0'){
                ch[i+2]='1';
            } else{
                ch[i+2] = '0';
            }

            bool Allzero = true;
            for(int i =0;ch[i]!='\0';i++){
                if(ch[i]!='0') {
                    Allzero= false;
                    break;
                }
            }

            if(Allzero){
                found = true;
                break;
            }
        
        }

        cout << (found ? "YES" : "NO") << endl;
        
    }

    
    return 0;
}