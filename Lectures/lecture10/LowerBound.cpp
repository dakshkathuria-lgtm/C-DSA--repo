#include<iostream>
using namespace std;

int lower_bound(int *p, int n , int key){
    int s =0, e = n-1;
    int ans = n;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(p[mid]>= key ){
            ans = mid;
            e = mid -1;
        } else{
            s = mid+1;
        }
    }

    return ans;
}

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

    int ans = lower_bound(a, n, target);

    cout << ans << endl;    
    
    return 0;
}