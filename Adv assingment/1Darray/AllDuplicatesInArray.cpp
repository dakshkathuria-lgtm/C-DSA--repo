#include<iostream> 
#include<climits>
using namespace std;

int main(){
    int n ;
    cin >>n;
    int a[n];
    int maxi = INT_MIN;
    for(int i =0;i<n;i++){
        cin >> a[i];
        if(maxi<a[i]) maxi = a[i];
    }

    int freq[maxi+1]{};
    for(int i =0;i<n;i++){
        int ce = a[i];
        freq[ce]+=1;
    }

    for(int i =0;i<maxi+1;i++){
        if(freq[i]>1){
            cout << i << " ";
        }
    }
    return 0;
}