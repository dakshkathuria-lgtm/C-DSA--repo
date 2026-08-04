#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    int maxi = INT_MIN;

    for(int i =0;i<n;i++){
        int sum =0;
        for(int j =i;j<n;j++){
            sum+=a[j];
            if(sum >maxi){
                maxi = sum;
            }
            for(int k =i;k<=j;k++){
                cout << a[k]<< " ";
            }
            cout << "=" << sum ;
            cout << endl;
        }
        cout << endl;
    }
    cout << maxi << endl;
    return 0;
}


// #include <climits>
// #include <iostream>
// using namespace std;

// // Computations : n*n*n
// int main() {
//   int n;
//   cin >> n;
//   int a[n];
//   for (int i = 0; i < n; i += 1) {
//     cin >> a[i];
//   }

//   // Idea: Generate all the Subarrays : Index Wise:
//   int maxi = INT_MIN;
//   // Go to every index and treat that index as the
//   //  starting point of the subarray.
//   for (int sp = 0; sp < n; sp += 1) {
//     // Current Starting Point : sp
//     //  FOr this sp print all the subarrays that
//     //  start from sp.
//     // sp---->sp
//     // sp--->sp+1
//     // sp---->sp+2

//     for (int ep = sp; ep < n; ep += 1) {
//       // You are currently at a subarray : [sp,ep]

//       int sum = 0;
//       // Current Subarray ka sum nikalo :
//       for (int k = sp; k <= ep; k += 1) {
//         sum += a[k];
//       }

//       // Current Subarray Sum is sum.
//       cout << sum << endl;
//       if (maxi < sum) {
//         maxi = sum;
//       }
//     }
//   }

//   cout << endl << "------------------" << endl;
//   cout << maxi << endl;
//   return 0;
// }   