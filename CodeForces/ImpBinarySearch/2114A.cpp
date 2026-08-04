#include<iostream>
#include<cstring>
#include<climits>
#include<ctype.h>
#include<cmath>
using namespace std;

char s[5];

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int num = stoi(s);
        double x = sqrt(num);
        int rx = (int)x;

        if(rx*rx!=num)
            cout << "-1" << endl;
        else{
            if(rx%2==0){
                int a =rx/2-1, b = rx/2+1;
                cout << a << " " << b << endl;
            } else{
                int a =1, b=rx-a;
                cout << a << " " << b << endl;
             }
        }
    }
    
    return 0;
}