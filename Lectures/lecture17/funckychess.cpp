#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
const int N = 10;
int dx[]{1, 1, 2, 2, -1, -1, -2, -2};
int dy[]{2, -2, 1, -1, 2, -2, 1, -2};

int n;
int grid[N][N]{};
int totalBoxes=0;

void input(){   
    cin >> n;
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> grid[i][j];
            if(grid[i][j]==1){
                totalBoxes++;
            }
        }
    }
}

// f(x,y) : maximum numbers of boxes where the knoght can go in a single path
int F(int x, int y){

    // stopping point dihar nhi as we r not sure wher eknoght will stop from this x, y
    
    // we don;t need this as we r only going to boxes wihch are unvisited in the current path
    // if(grid[x][y]==0){
    //     return 0;
    // }

    //CURRENT STATE :F(x,y)
    grid[x][y]= 0; // to mark this box as visited
    int maxi = 0; // stores the ans i.e max no of boxes where knoght can go


    for(int i =0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
    


        // cehck if vialid or not nx, ny
        if(nx>=0 and ny >=0 and nx<n and ny<n and grid[nx][ny]==1){
            int smallAns = F(nx, ny);

            maxi = max(maxi , smallAns);
        }

    }


    grid[x][y]=1; // backtracking

    return 1 + maxi;

}



int main(){

    input();

    if(grid[0][0]==0){
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int ans = F(0,0);

    cout << totalBoxes - ans << endl;

    return 0;
}
