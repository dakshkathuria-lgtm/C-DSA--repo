#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int givenSum = 0;
    for(int i =1;i<n;i++){
        int x;
        cin>>x;
        givenSum+=x;
    }
    int totalSum = n*(n+1)/2;
    cout << totalSum - givenSum << endl;
    return 0;
}