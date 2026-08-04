#include<iostream>
#include<climits>
using namespace std;


int KokoEatingBananaBinary(int a[], int n , int hour){
    int maxi = INT_MIN;
    for(int i =0;i<n;i++){
        if(a[i]>maxi) maxi = a[i];
    }
    // BINARY SEARCH
    long long s =1, e = maxi, ans =-1;
    while(s<=e){
        
        long long mid = s+(e-s)/2; // mid banana per hr banana khake h hour ke andar kha paunga ya nhi
        long long ch =0;
        for(int j =0;j<n;j++){
            ch +=((a[j]-1+mid)/mid);
        }

        if(ch<=hour){
            ans = mid;
            e = mid-1;
        } else{
            s = mid+1;
        }
    }
    return ans;
}


int KokoEatingBananaBrute(int a[], int n , int hour){
    // Computations - 10^13
    // BRUTE FORCE - find 1st value of k satisying ek ek karke
    int maxi = INT_MIN;
    for(int i =0;i<n;i++){
        if(a[i]>maxi) maxi = a[i];
    }
    for(int k =1;k<=maxi;k++){
        int ch=0;
        for(int j = 0;j<n;j++){
            ch += ((a[j]+k-1)/k);
        }
        if(ch<=hour){
            return k;
        }
    }
    return -1;
}


int main(){ 
    int n;
    cin >> n;
    int a[n];

    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    int hour;
    cin >> hour;

    cout << KokoEatingBananaBrute(a, n, hour)<<endl;
    cout << KokoEatingBananaBinary(a, n, hour) << endl;
}
