#include<iostream>
#include<algorithm>
#include<climits>
#include<ctype.h>
#include<cstring>
using namespace std;


// F(index) : min cost to go from index to nth stair
int F(int n , int value[], bool visited[], int index){

    if(index==n){
        // min cost to go from nth stair to nth stair
        return 0;
    }

    // if there is no path available then return a very large value
    int op1 = 1e9, op2 = 1e9;


    // before evalutating current state make current stair as visited 
    // s othat whle evaluating my state f(index) I don;t revissit this current stair 
    // represented by index.

    visited[index] = 1;

    // EVALUATE ANSWER FOR STATE F(INDEX)

    if(index+1<=n and visited[index+1]==0){
        op1 = 1 + F(n, value, visited, index+1 );
    }

    if(index + value[index]<=n && visited[index + value[index]]==0  && index + value[index]>=0){
        op2 = 1 + F(n, value, visited, index + value[index]);
    }

    // backtracking current path se nikala so that vaapis visit karke saare raaste vealate kar sakta
    visited[index] = 0;


    int ans = min (op1, op2);
    return ans;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int value[n]{} ;
        for(int i =0;i<n;i++){
            cin >> value[i];
        }

        // konsa stair current path mei visisted hai konsa nhi
        bool visited[n]{};

        int ans = F(n, value , visited, 0);

        if(ans > 1e8){
            cout << -1 << endl;
        } else{
            cout << ans << endl;
        }

        // 1 test case ke baad do work again
        // either do 0 of visited by for loop or

        memset(visited, 0, sizeof(visited));
    }



    return 0;
}