#include<iostream> 
#include<climits>
using namespace std;
int main(){
    int n , t;
    cin >> n >> t;
    int a[n];
    for(int i =0;i<n;i++){
        cin>> a[i];
    }
    
    int maxBOk = INT_MIN;
    for(int i =0;i<n;i++){
        int count =0;
        int sum = 0;
        for(int j =i;j<n;j++){
            sum+=a[j];
            if(sum <= t){
                count++;
            } else{
                break;
            }
        }
        if(maxBOk < count) maxBOk = count;
    }

    cout << maxBOk << endl;
    return 0;
}