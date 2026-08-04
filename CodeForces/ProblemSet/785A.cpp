#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int sum =0;
    while(n--){
        char ch[101];
        cin >> ch;
        if(strcmp(ch,"Tetrahedron")==0){
            sum+=4;
        } else if(strcmp(ch, "Cube")==0){
            sum+=6;
        } else if(strcmp(ch,"Octahedron")==0){
            sum+=8;
        } else if(strcmp(ch,"Dodecahedron")==0){
            sum+=12;
        } else{
            sum+=20;
        }
    }

    cout << sum << endl;

    return 0;
}