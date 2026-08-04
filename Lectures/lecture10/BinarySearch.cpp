#include<iostream>
using namespace std;
int main()
{
    int n ;
    cin >> n;
    int a[n];
    for ( int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int target;
    cin >> target;

    // initialise with -1 or n as both index do not exist
    int ans = n; // stores the potential ans to the ques

    int s = 0, e = n-1;
    while (s<=e)
    {
        int mid = s+(e-s)/2;
        if(a[mid]==target){
            ans = mid;
            break;
        } else if(a[mid]>target){
            e = mid-1;
        } else{
            s = mid+1;
        }
    }

    cout << ans << endl;
    
    
    return 0;
}