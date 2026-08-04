#include<iostream>
using namespace std;

bool distinct(int year){
    int freq[10]{};
    
    while(year > 0){
        int digit = year % 10;
        freq[digit]++;
        year /= 10;
    }

    for(int i =0;i<10;i++){
        if(freq[i]>1)
            return false;
    }
    return true;
}
int main(){
    int y ;
    cin >> y;

    y++;

    while(!distinct(y)){
        y++;
    }
    
    cout << y << endl;
    
    return 0;
}