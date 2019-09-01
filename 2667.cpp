#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int map[26][26];
bool visited[26][26];
int move_x[4]={0,0,1,-1};
int move_y[4]={1,-1,0,0};
int apar[1010];
int cnt = 0;
int N;



void DFS(int x, int y){
    visited[x][y] = true;
    apar[cnt]++;
    for(int i=0; i<4; i++){
        int nx = x + move_x[i];
        int ny = y + move_y[i];
        if(0<=nx && nx<N && 0<=ny && ny<N){
            if(!visited[nx][ny] && map[nx][ny]){
                DFS(nx,ny);
            }
        }
    }
}

int main(){

    scanf("%d",&N);
    
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            scanf("%1d",&map[i][j]);
        }
    }

    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            if(!visited[i][j] && map[i][j]){
                DFS(i,j);
                cnt++;
            }
        }
    }    
    printf("%d\n", cnt);
    sort(apar, apar+cnt);
    for(int i=0; i<cnt; i++){
        printf("%d\n", apar[i]);
    }
    

    return 0;
}