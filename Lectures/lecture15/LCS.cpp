#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
string s, t;

//f(x,y): ength of lcs in string s from x to n-1 and string t from y to n-1
// where n and m are the length of the string s & t respectively

int f(int x, int y){
    if(x>=s.length() or y>=t.length()){
        // taking about f(n,t) 0r f(t,m)
        return 0;
    }   

    //current state : F(x,y)
    // xth index par in string s and yth index par in string t

    if(s[x]==t[y]){
        return 1 + f(x+1, y+1);
    } else{

        // len of lCS in string s from xth idx to n-1 and in string t 
        // from yth idx to n-1 where skipping t[y]
        int op1 = f(x,y+1);

        // len of lCS in string s from xth idx to n-1 and in string t 
        // from yth idx to n-1 where skipping s[x]
        int op2 = f(x+1, y);


        return max(op1, op2);
    }
}


int main(){
    cin >> s>> t;

    // starting point
    cout <<  f(0,0) << endl;


    return 0;
}