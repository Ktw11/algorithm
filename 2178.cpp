#include <stdio.h>
#include <queue>

#define MAX 102

using namespace std;

int maze[MAX][MAX];
int move_x[4] = {0,0,-1,1};
int move_y[4] = {1,-1,0,0};
int N,M;
queue<pair<int,int> > Q;

void BFS(){
    Q.push(make_pair(1,1));
    int nx,ny;

    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++){
            int nx = x + move_x[i];
            int ny = y + move_y[i];
            if(0<nx && nx<=N && 0<ny && ny<=M && maze[nx][ny]==1){
                Q.push(make_pair(nx,ny));
                maze[nx][ny] = maze[x][y] + 1;
            }
        }
    }
    
}

int main() {
    
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d", &maze[i][j]);
        }
    }
    
    BFS();

    printf("%d\n",maze[N][M]);

    return 0;
}