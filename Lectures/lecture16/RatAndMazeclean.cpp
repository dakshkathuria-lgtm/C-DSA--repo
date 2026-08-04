#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
const int N = 1003;

int n , m;

char maze [N][N];
bool visited[N][N]{}; 
bool sol [N][N]{};

bool f(int x, int y){
    if(x==n and y ==m){
        sol[x][y]=1;
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }

        return true; 
    }
    
    if(visited[x][y]!=0){

        return false;
    }

    visited[x][y]=1;
    sol[x][y] =1;


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
    
    sol[x][y]=0;
    return false;
}


int main(){
    cin >> n >> m;

    for(int i =1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> maze[i][j];

            if(maze[i][j]=='X'){
                visited[i][j] = 1;
            }
        }
    }

    bool ans = f(1,1);
    if(ans==0){
        cout << "No path exists";
    }

    return 0;
}