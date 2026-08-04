#include<iostream>
#include<climits>
using namespace std;
const int N= 1e5 + 3;

int t, n;
int a[N], b[N], c[N];
int maxia = INT_MIN, maxib = INT_MIN, maxic=INT_MIN;
int max_a=0, max_b=0,  max_c=0;


int main(){

    cin >> t;
    while(t--){
        cin >> n;
        for(int i =0;i<n;i++){
            cin >> a[i];
        }
        for(int i =0;i<n;i++){
            cin >> b[i];
        }
        for(int i =0;i<n;i++){
            cin >> c[i];
        }


        
        for(int i =0;i<n;i++){
            if(a[i]>maxia){
                maxia = a[i];
                max_a = i;
            }
        }

        for(int i =0;i<n;i++){
            if(b[i]>maxib && max_b != max_a){
                maxib = b[i];
                max_b = i;
            }
        }

        for(int i =0;i<n;i++){
            if(c[i]>maxic && max_c!=max_b && max_c!=max_a){
                maxic = c[i];
                max_c = i;
            }
        }

        int sum = maxia + maxib + maxic;
        cout << sum << endl;
    }
    



    return 0;
}