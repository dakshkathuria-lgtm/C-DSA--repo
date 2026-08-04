#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;

int n;
int a[N];
int key;

int F(int s, int e){

    if(s>e){
        return false;
    }

    int mid = s+(e-s)/2;


    if(a[mid]==key){
        return true;
    } else if(a[mid]>key){
        e = mid-1;
        return F(s, e);
    } else{
        s= mid+1;
        return F(s, e);
    }
}

int main(){

    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    cin >> key;

    sort(a, a+n);

    int s =0, e = n-1;

    cout << F(s, e) << endl;

    return 0;
}