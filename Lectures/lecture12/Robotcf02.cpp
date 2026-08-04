#include<iostream>
#include<climits>
#include<cstring>
#include<ctype.h>
using namespace std;


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

bool com(string &x, string &y){
    string xy = x+y;
    string yx=y+x;
    if(noise2(xy)>noise2(yx)){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n ;
    cin >> n;

    string s[n];
    for(int i =0;i<n;i++){
        cin >> s[i];
    }

    for (int i = 0; i < n - 1; i += 1) {

        for (int j = 0; j < n - i - 1; j += 1) {
            if ((com(s[j], s[j + 1]) == 0)) {
                
                swap(s[j], s[j+1]);
        
            }
        }
    
    }

    // after this we have the esired arrangement of all the strings 
    // now form the final string and print the noise of this final string

    string final{" "};
    for(int i =0;i<n;i++){
        final +=s[i];
    }

    cout << noise2(final) << endl;
    
    return 0;
}