#include<iostream>
#include<climits>
using namespace std;
int main(){
    int t;
    cin >>t ;
    while(t--){
        int n ;
        cin >> n;
        int a[n+1];
        int maxi = 0;
        for(int i =1;i<=n;i++){
            cin >> a[i];
            if(a[i]> maxi ) maxi = a[i];
        }

        int freq[maxi +1]{};
        for(int i =1;i<=n;i++){
            int ce = a[i];
            freq[ce]+=1;
        }

        int highfreqele = 0;
        for(int i =1;i<maxi+1;i++){
            if(freq[i]>1){
                highfreqele = i;
            }
        }

        for(int i =1;i<=n;i++){
            if(a[i]!=highfreqele){
                cout << i << endl;
                break;
            }
        }

        
    }
    return 0;
}