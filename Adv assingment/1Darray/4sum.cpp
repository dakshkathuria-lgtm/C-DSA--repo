#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    for(int i =0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int target;
    cin >> target;

    for(int i =0;i<n-3;i++){
        if(i>0 && a[i]==a[i-1]) continue;
        for(int j =i+1;j<n-2;j++){
            if(j>i+1 && a[j]==a[j-1]) continue;
            int k =j+1, l=n-1;
            while(k<l){
                if(a[i]+a[j]+a[k]+a[l]==target){
                    cout << a[i] << " " << a[j] << " " << a[k] << " " << a[l] << endl;
                    k++, l--;
                    while(k<l && a[k]==a[k-1]){
                        k++;
                    }
                    while (k < l && a[l] == a[l + 1])
                        l--;
                } else if(a[i]+a[j]+a[k]+a[l]>target){
                    l--;
                } else{
                    k++;
                }
            }

        }
    }
    return 0;   
}