#include<iostream> 
#include<string>
using namespace std;
int main(){
    int a , b;
    cin >> a >> b;
    string s;
    cin >> s;
    if(s[a]!='-'){
        cout <<"No"<<endl;
        return 0;
    }
    for(int i =0;s[i]!='\0';i++){
        if(i==a) continue;
        if(!(s[i] >= '0' && s[i] <= '9')){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes"<<endl;
}