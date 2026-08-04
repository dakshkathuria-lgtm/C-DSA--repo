// frequency nikalani
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

int upper_bound(int *p, int n , int key){
    int s =0, e = n-1;
    int ans = n;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(p[mid]> key ){
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

    int ans1 = upper_bound(a, n, target);
    int ans2 = lower_bound(a, n , target);

    cout << ans1 << endl;
    cout << ans2 << endl;  
    
    cout << ans2 - ans1 << endl;
    
    return 0;
}