#include<iostream>
#include<cstring>
#include<vector>
#include<climits>
using namespace std;

bool CanPlace(vector<vector<char>>&board, char ch, int row, int col){
    // check current row
    for (int c = 0;c<9;c++){
        if(board[row][c]==ch){
            return false;
        }
    }

    // checl coloumns
    for (int r = 0;r<9;r++){
        if(board[r][col]==ch){
            return false;
        }
    }

    // checl submatrix
    int sx = (row/3) * 3;
    int sy = (col/3) * 3;

    for(int i =sx;i<sx+3;i++){
        for(int j = sy;j<sy+3;j++){
            if(board[i][j]==ch){
                return false;
            }
        }
    }

    return true;
}

bool f(vector<vector<char>>& board, int r, int c){
    if(r==9){
        return true;
    }

    if(c==9){
        return f(board, r+1, 0);
    }

    //current state f(board, r, c)

    if(board[r][c]!='.'){
        return f(board, r, c+1);
    }
    

    // ccurrent state f(board, r, c)
    // try putting all no from 1 to 9 and then for that ask recursion if it is a
    // able to solve the rest of soduko or not

    for(char x = '1' ; x = '9';x++){
        // check if this can be placed here or not?
        if(CanPlace(board, x, r, c)==1){
            // place cur no x at board[r][c] put this number and ask recursion to do the rest
            board[r][c] = x;
            bool smallAns = f(board, r, c+1);

            if(smallAns==1){
                return true;
            }

            // if am standnig here recursion was not bale to solve
            // therefore backtrack

            board[r][c] = '.';  // EK EK KARKE KAR RHE i.e putting ga number then putting a dot and then 
                                    // updating it to a new number;
        } 
    }
    // board[r][c] = '.'; // SAARE EK SAATH i.e piut a number update it tillu have 9 and u r out of the loop and then 
                        // amek number in current box as . 


    // current state d(board, r, c);
    //recurion wanm't able to solve

    return false;
}

void solveSudoku(vector<vector<char>>& b){
    //starting point
    bool useless = f(b, 0, 0);




    return;
}


int main(){

    vector<vector<char>> board(9, vector<char>(9));

    for(int i =0;i<9;i++){
        for(int j = 0;j<9;j++){
            cin >> board[i][j] ; // since size diya hua tha
        }
    }

    solveSudoku(board);

    for(int i =0;i<9;i++){
        for(int j = 0;j<9;j++){
            cout << board[i][j] << " "; // since size diya hua tha
        }
        cout << endl;   
    }


    return 0;
}