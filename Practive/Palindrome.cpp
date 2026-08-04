#include<iostream>
using namespace std;
int main(){
    char ch[100];
    cin >> ch;
    int len = 0;
    for(int i =0;ch[i]!='\0';i++){
        len+=1;
    }

    int i = 0, j = len-1;
    while(i<j){
        if(ch[i]!=ch[j]){
            cout << "No" << endl;
            return 0;
        }
        i++, j--;
    }
    cout << "Yes"<< endl;
}