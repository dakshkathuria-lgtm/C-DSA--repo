// also called counting sort
// now what if user inputs a negative element
// in that case we use shifting 
// updated scale = original scale - min
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i =0;i<n;i++){
        cin >> a[i];
        if(a[i]>maxi){
            maxi=a[i];
        }
        if(a[i]<mini){
            mini=a[i];
        }
    }
    
    int freq[maxi-mini+1]{};
    // Build this Freq array :
    // Iterate over the original array and build this freq array.

    for(int i =0;i<n;i++){
        int ce = a[i];
        int us = ce - mini;
        freq[us]+=1;
    }

    // Freq array me  i index : Element of the original array
    //   freq[i] : Freq hain i as a element in original array.

    for(int i =0;i<maxi-mini+1;i++){
        if(freq[i]>0){
            int os = i + mini;
            cout << os << "->" << freq[i] << endl;
        }
    }
    return 0;   
}