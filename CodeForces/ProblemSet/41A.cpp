#include<iostream>
using namespace std;
int main(){
    char s[100];
    char t[100];
    cin >> s ;
    cin >> t;

    int len_t =0;
    for(int i =0;t[i]!='\0';i++){
        len_t++;
    }

    int len_s =0;
    for(int i =0;s[i]!='\0';i++){
        len_s++;
    }

    if(len_s!=len_t){
        cout << "NO" << endl;
        return 0;
    }

    int i =0, j=len_t-1;
    while (i<j)
    {
        int temp = t[i];
        t[i] = t[j];
        t[j] = temp;
        i++, j--;

    }

    for(int i =0;i<len_s;i++){
        if(s[i]!=t[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}