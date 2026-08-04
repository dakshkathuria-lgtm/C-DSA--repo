#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    char ch[]{"codeforces"};
    while(t--){
        char c;
        cin >> c;
        bool flag = false;
        for(int i =0;ch[i]!='\0';i++){
            if(ch[i]==c){
                flag = true;
                break;
            }
        }
        if(flag == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
