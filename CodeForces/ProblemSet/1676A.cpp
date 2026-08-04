#include<iostream>
#include<cstring>

using namespace std;

char ch[7];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> ch;

        int sumFirst = 0, sumLast = 0;
        for(int i =0;i<3;i++){
            sumFirst+=ch[i];
        }
        for(int i =3;ch[i]!='\0';i++){
            sumLast+=ch[i];
        }

        if(sumFirst==sumLast) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}