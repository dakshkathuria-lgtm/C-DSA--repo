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

    int maxp = INT_MIN;

    for(int i =0;i<n;i++){
        int product = 1;
        for(int j =i;j<n;j++){
            product *=a[j];
            if(maxp < product) maxp = product;
            for(int k =i;k<=j;k++){
                cout << a[k] << " ";
            }
            cout << "= " << product << endl;
        }
        cout << endl;
    }
    cout << maxp << endl;

    return 0;
}
