#include<iostream>
#include<climits>
#include<cstring>
#include<ctype.h>
using namespace std;

int noise(string &s){

    int ans = 0;
    for(int i =0;i<s.length();i++){
        int count_h = 0;
        if(s[i]=='s'){
            for(int j = i+1;j<s.length();j++){
                if(s[j]=='h'){
                    count_h++;
                }
            }
        }
        ans+=count_h;
    }

}

int noise2(string &s){
    int count_s=0, ans =0;
    for(int i =0;i<s.length();i++){
        if(s[i]=='s'){
            count_s++;
        } else{
            ans +=count_s;
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;

    noise(s);
    return 0;
}