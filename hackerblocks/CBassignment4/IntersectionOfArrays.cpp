#include<iostream>
#include<climits>
#include<math.h>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n], b[n];
    int maxi1 = INT_MIN;
    int maxi2 = INT_MIN;
    for(int i =0;i<n;i++){
        cin >> a[i];
        if(a[i]>maxi1) maxi1 = a[i];
    }
    for(int i =0;i<n;i++){
        cin >> b[i];
        if(b[i]>maxi2) maxi2 = b[i];
    }

    int freq1[maxi1 + 1]{};
    for(int i =0;i<n;i++){
        int ce1 = a[i];
        freq1[ce1]+=1;
    }

    int freq2[maxi2+1]{};
    for(int i =0;i<n;i++){
        int ce2 = b[i];
        freq2[ce2]+=1;
    }

    cout << "[" ;
    bool first = true;
    for(int i = 0; i <= min(maxi1, maxi2); i++){
        int common = min(freq1[i], freq2[i]);
        while (common--)
        {
            if(!first) cout << ", ";
            cout << i;
            first = false;
        }
        
    }
    cout << "]";

    return 0;
}