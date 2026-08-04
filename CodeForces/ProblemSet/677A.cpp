#include<iostream>
using namespace std;
int main(){
    int n , h;
    cin >> n >> h;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int bentWidthSum = 0;
    int width ;
    for(int i =0;i<n;i++){
        if(a[i]<=h){
            width=1;
            bentWidthSum+=width;
        } else{
            width = 2;
            bentWidthSum+=width;
        }
    }

    cout << bentWidthSum << endl;
    return 0;
}
