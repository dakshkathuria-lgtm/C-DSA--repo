#include<iostream>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int pre[101][101]{};

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin >> pre[i][j];
        }
    }

    // METHOD 1- RECOGNIZING THE PATTERN
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(i==0 and j==0){
                continue;
            } else if(i==0){
                pre[i][j] = pre[i][j-1] + pre[i][j];
            } else if(j==0){
                pre[i][j] = pre[i-1][j] + pre[i][j];
            } else{
                pre[i][j] = pre[i-1][j] + pre[i][j-1] + pre[i][j] - pre[i-1][j-1];
            }
        }
    }

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "------------------------------" << endl;


    // METHOD 2- RESOLVING THE DIMENSIONS

    // row ko resolve kiya
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(j==0){
                continue;
            }
            pre[i][j] = pre[i][j-1] + pre[i][j];
        }
    }

    // resolve the second dimension
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i==0){
                continue;
            }
            pre[i][j] = pre[i-1][j] + pre[i][j];
        }
    }

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}