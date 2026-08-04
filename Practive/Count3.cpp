// FREQ OF ALL ELEMENTS BUT REMOVE DUPLICATES 
// BUT WITHOUT CREATING ANOTHER ARRAY
// THEREFORE IN PLACE ONLY
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    
    for(int i =0;i<n;i++){
        if(a[i]==INT_MAX) continue;
        int cnt = 1;
        int key =a[i];
        for(int j=i+1;j<n;j++){
            if(a[j]==key){
                cnt++;
                a[j]=INT_MAX;
            }
        }
        cout << key<< "---->" << cnt << endl;
    }
    return 0;
}   