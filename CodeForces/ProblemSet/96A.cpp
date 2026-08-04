#include<iostream>
#include<string>
#include<climits>
using namespace std;


int main(){
    
    char str[100];
    cin >> str; // getline with string and cin.getline with char arrays
    int len =0;
    for(int i =0;str[i]!='\0';i++){
        len++;
    }

    int sp =0, ep=0;
    int ans = INT_MIN;
    for(;ep<len;ep++){
        //EXPANSION


        //SHRKING
        while(str[ep]!=str[sp] && sp<=ep){
            sp++;
        }


        // UPDATION
        if(ep-sp+1>ans){
            ans = ep-sp+1;
        }
    }

    if(ans>=7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
