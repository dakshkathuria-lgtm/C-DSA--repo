#include<iostream>
using namespace std;

bool palindrome(long long x){
    long long original = x;
    long long reverse= 0;;
    while(x>0){
        int ld =x%10;
        reverse = reverse*10 + ld;
        x=x/10;
    }
    return reverse==original;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n ;
        cin >> n;
        long long b =0;
        long long a;
        bool flag =false;
        for(;b<=n;b+=12){
            a = n-b;
            if(b%12==0 && palindrome(a)==1){
                flag=true;
                break;
            }
        }
        if(flag ==true)
            cout << a << " " << b << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}