#include<iostream>
using namespace std;


int main(){
    int n ;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    
    int SerejaSum = 0, DimaSum = 0;

    int i =0, j= n-1;

    int maxelement = 0;

    int cnt =0;

    while (i<=j)
    {
        if (a[j]>a[i])
        {
            maxelement = a[j];
            j--;
        } else{
            maxelement = a[i];
            i++;
        }
        
        cnt++;

        if(cnt%2!=0) SerejaSum+=maxelement;
        else DimaSum+=maxelement;
        
    }
    

    cout << SerejaSum << " " << DimaSum << endl;

    return 0;
}