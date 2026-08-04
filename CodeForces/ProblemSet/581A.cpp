#include<iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    int fashion = min(a,b);
    a -=fashion;
    b-=fashion;

    int same=0;
    if((a==1 && b==0) || (a==0 && b==1)){
        cout << fashion << " " << same << endl;
        return 0;
    } else{
        if(a==0){
            while(b!=0){
                same+=1, b-=2;
            }
        } else{
            while(a!=0){
                same+=1, a-=2;
            }
        }
    }

    

    cout << fashion << " " << same <<endl;
    return 0;
}