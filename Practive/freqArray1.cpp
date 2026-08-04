// also called counting sort
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int maxi = INT_MIN;
    for(int i =0;i<n;i++){
        cin >> a[i];
        if(a[i]>maxi){
            maxi=a[i];
        }
    }
    
    int freq[maxi+1]{};
    // Build this Freq array :
    // Iterate over the original array and build this freq array.

    for(int i =0;i<n;i++){
        int ce = a[i];
        freq[ce]+=1;
    }

    // Freq array me  i index : Element of the original array
    //   freq[i] : Freq hain i as a element in original array.

    for(int i =0;i<maxi+1;i++){
        if(freq[i]>0){
            cout << i << "->" << freq[i] << endl;
        }
    }
    return 0;   
}