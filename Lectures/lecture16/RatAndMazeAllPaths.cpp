#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
const int N = 1003;

int n , m;

char maze [N][N];
bool visited[N][N]{}; 
bool sol [N][N]{};

// find rightmost path from x,y to n, m
bool f(int x, int y){
    if(x==n and y ==m){
        sol[x][y]==1;
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl << "------------------" << endl;

        return false; // ans mil gya ab yaha se kya return karna
    }

    
    if(visited[x][y]!=0){
        // already visited that so and nhi mila isse;
        return false;
    }

    visited[x][y]=1;
    sol[x][y] =1;


    // tryna go in the right direction and will aks recursion that mere current
    // x,y se right vaale x,y+1 bahan se end tak m,n tak kio rassta mila


    if(y+1<=m and visited[x][y+1]==0){
        bool rightAns = f(x, y+1);

        if(rightAns==1){
            return true;
        }
    }


    if(x+1<=n and visited[x+1][y]==0){
        bool downans = f(x+1, y);

        if (downans==1){
            return true;
        }
    }
    

    visited[x][y]=0;
    sol[x][y]==0;
    return false;
}


int main(){
    cin >> n >> m;

    for(int i =1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> maze[i][j];

            //update visited matrix for 'x' charcter in maze
            if(maze[i][j]=='X');{
                visited[i][j] = 1;
            }
        }
    }

    bool ans = f(1,1);
    if(ans==0){
        cout << "No path exists";
    }

    // recursion ke andar hi final matrix print karvado



    return 0;
}