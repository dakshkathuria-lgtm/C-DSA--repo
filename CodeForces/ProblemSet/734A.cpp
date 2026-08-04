#include<iostream>
#include<string>
#include<climits>
using namespace std;
int main(){
    int n ;
    cin >> n;
    char ch[n];
    cin >> ch;

    int cnt_a = 0, cnt_d=0;
    
    for(int i =0;ch[i]!='\0';i++){
        if(ch[i]=='A'){
            cnt_a++;
        } else{
            cnt_d++;
        }
    }

    if(cnt_a>cnt_d){
        cout << "Anton" << endl;
    } else if(cnt_a==cnt_d){
        cout << "Friendship" << endl;
    } else{
        cout << "Danik" << endl;
    }
    return 0;
}