#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

bool CanPlace(int &row, int &col, int n, vector<string>&current){

    // check current row
    for(int y = 0;y<col;y++){
        if(current[row][y]=='Q'){
            return false;
        }
    }

    // check current coloumn
    for(int x = 0;x<row;x++){
        if(current[x][col]=='Q'){
            return false;
        }
    }

    // check left diagonal
    int r = row, c = col;
    while(r>=0 and c>=0){
        if(current[r][c]=='Q'){
            return false;
        }

        r-- , c--;
    }

    // check right diganoal
    r = row, c = col;
    while(r>= 0 and col<n){
        if(current[r][c]=='Q'){
            return false;
        }
        r--, c++;
    }

    return true;
}

bool f(int row, vector<string>&current, vector<vector<string>> &ans, int n){
    if(row==n){
        ans.push_back(current);
        return false;
    }

    // current state
    for(int col = 0;col<n;col++){

        if(CanPlace(row, col, n, current) ==1){
            current[row][col] = 'Q';

            bool smallAns = f(row+1, current, ans, n);
            if(smallAns==true){
                return true;
            }

            // ya toh sol milgya hoag varna hoga hi nhi
            current[row][col] = '.';
        }
    }

    // agar mai khi nhi rakh paaya then mai cur row par khi par queen nhi rakh paaya
    // and hence pichle state par jao jisne f(row) ko call kiya and usko batayo ki jaha queem rkahi hai
    // voh galat jagah hao

    return false;
}

vector<vector<string>> solveNQueens(int n){

    vector<vector<string>> ans; // will storea all the pssible combinations of the wueen
    vector<string> current(n , ""); // will store only 1 combbination
    string s(n,'.'); // ek row of my matrix ko represent aise

    //initialsing cur str ko jo eo combinatino store karta hai

    for(int i =0;i<n;i++){
        current[i] = s;
    }

    // starting point
    bool useless = f(0, current, ans,n); // for saare lsn orint this is useless




    return ans;
}  

void PrintUsingForLoop (vector<vector<string>> &ans){
    for(int i =0;i<ans.size();i++){
        // resovle 2d str
        for(int j = 0;j<ans[i].size();j++){
            cout << ans[i][j] <<endl;
        }
        cout << endl;
    }

    cout << endl << "-------------------------" << endl;
}

void PrintUsingForEachLoop(vector<vector<string>> &ans){
    for(vector<string> x: ans){
        for( string y :x ){
            cout << y << endl;
        }
        cout << endl;
    }

    cout << endl << "--------------------------" << endl;
}

int main(){
    int n;
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);

    if(ans.size()==0){
        cout << "No Solution exists" << endl;
    }

    PrintUsingForLoop(ans);

    PrintUsingForEachLoop(ans);
}