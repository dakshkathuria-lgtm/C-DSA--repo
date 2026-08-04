#include<iostream>
#include<ctype.h>
#include<algorithm>
using namespace std;
int main(){

    // int x, y, z;
    // cin >> x >> y >> z;
    
    int a[3];
    for(int i =0;i<3;i++){
        cin >> a[i];
    }
    sort(a,a+3);
    
    int minDis = (a[2] - a[1]) + (a[1] - a[0]);
    cout << minDis << endl;
    return 0;
}