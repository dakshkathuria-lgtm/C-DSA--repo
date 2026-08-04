#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n], b[n];
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for(int i =0;i<n;i++){
        cin >> a[i];
        if(a[i]>max1) max1 = a[i];
    }
    for(int i =0;i<n;i++){
        cin >> b[i];
        if(b[i]>max2) max2 = b[i];
    }

    int maxVal = (max1>max2) ? max1:max2;

    int freq1[maxVal+1]{};
    for(int i =0;i<n;i++){
        int ce1 = a[i];
        freq1[ce1]+=1;
    }

    for(int i =0;i<n;i++){
        int ce2 = b[i];
        freq1[ce2]-=1;
    }

    for(int i =0;i<maxVal+1;i++){
        if(freq1[i]!=0) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    
}