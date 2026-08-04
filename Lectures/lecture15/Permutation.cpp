#include<iostream>
#include<cstring>
#include<ctype.h>
#include<string>
using namespace std;

string s;

void f(string s, int x){
    if(x==s.length()){
        cout << s << endl;
        return;
    }

    for(int i = x;i<s.length();i++){
        swap(s[x], s[i]);
        f(s, x+1);
    }

    return ;    
}

void f1(string &s, int x){
    if(x==s.length()){
        cout << s << endl;
        return;
    }

    for(int i = x;i<s.length();i++){
        swap(s[x], s[i]);
        f1( s, x+1);

        // my recursion call is over: mera f(x+1) ka kaam hogyahoga tbhi mai niche
        // aaya hu////current state ka ans nikal liya by saying f(X+1) ki permutations recursion ne dedi and aapne s[x] 
        // and s[i] ko swap kiya..now i hv to go pichel sate par and call vaale kaam 
        // ko cancel karna chahata hu...so what we swapped s[x] and s[i] in state f(x)
        // so swap it again in order to reinstate irigunal state of f(x)

        swap(s[x], s[i]); // THIS IS BACKTRACKING 
        // BAKCTRACKING no nedd in pass by alue only done in pass by reference
    }

    return ;
}

int main(){
    
    cin >> s;


    f(s, 0);

    cout << "________________________________" << endl;

    // f1(s, 0);

    return 0;
}